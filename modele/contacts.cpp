#include "contacts.h"
#include <QFile>
#include <QTextStream>
#include "structure.h"
#include "texte.h"
#include "personne.h"
#include "organisme.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include "search.h"
#include "email.h"

Contacts::Contacts(QObject *parent) :
    QObject(parent)
{
    mComp=new Comp(true,tr("nom"));
}


void Contacts::ajouterContact(Contact * contact)
{
    mContacts<<contact;
    emit dataChanged();
    connect(contact,SIGNAL(dataChanged()),this,SIGNAL(dataChanged()));
}

Personne * Contacts::ajouterPersonne()
{
    Personne * nouveau=Personne::creerDefaut();
    ajouterContact(nouveau);
    return nouveau;
}

Organisme * Contacts::ajouterOrganisme()
{
    Organisme * nouveau=Organisme::creerDefaut();
    ajouterContact(nouveau);
    return nouveau;
}


void Contacts::supprimerContact(const int n)
{
    mContacts.removeAt(n);
    emit dataChanged();
}

int Contacts::nombre() const
{
    return mContacts.length();
}

Contact * Contacts::operator[](const int n) const
{
    return mContacts[n];
}

QString parseString(QString s)
{
    return s.replace("\\n","\n").replace("\\,",",").replace("\\\"","\"");
}

QString unParseString(QString s)
{
    return s.replace("\n","\\n").replace(",","\\,").replace("\"","\\\"");
}

void Contacts::changerTri(Comp * comp)
{
    mComp=comp;
    trier();
}


void essayerEncore(Contact * c)
{
    c->essayerEncore();
}

void Contacts::charger(QString nomFichier)
{

    mContacts.clear();
    QFile fichier(nomFichier);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);
    QString ligne;
    Contact * contact=NULL;
    int ini=0;
    QString version="";
    QString kind="individual";
    while(! flux.atEnd())
    {
        ligne = flux.readLine();
        QRegExp rx("^item[0-9]+\\.(.+)$");
        if(rx.indexIn(ligne)!=-1) ligne=rx.cap(1);
        QStringList l=ligne.split(":");
        QString nom=l.first();
        l.pop_front();
        QStringList noms=nom.split(";");
        QString vnom=noms[0];
        QString valeur=l.join(":");
        QStringList valeurs=valeur.split(";");
//        std::cout<<nom.toStdString()<<"\n";
        if(nom=="BEGIN" && valeur=="VCARD" && ini==0 && contact==NULL)
        {
            ini=1;
        }
        else if(nom=="VERSION" && ini==1 && contact==NULL)
        {
            version=valeur;
            ini++;
        }
        else if(ini==2 && contact==NULL)
        {
            if(vnom=="KIND") kind=valeur;
            contact=vnom=="KIND" ?(valeur=="individual" ? (Contact *)new Personne() : (Contact *)new Organisme()) : (Contact *)new Personne();
            ini=0;
        }
        if(contact!=NULL)
        {
            if(nom=="END" && valeur=="VCARD")
            {
                if(!(contact->aNom())) contact->ajouterChamp(tr("nom"),kind=="individual" ? Personne::gnom("","") : Organisme::gnom("",""));
                ajouterContact(contact);
                contact=NULL;
                ini=0;
                version="";
                kind="individual";
            }
            else if(vnom=="N") contact->ajouterChamp(tr("nom"),kind=="individual" ? Personne::gnom(valeurs.length()>0 ? valeurs[0] : "",valeurs.length()>1 ? valeurs[1] : "")
                                                                                  : Organisme::gnom(valeurs.length()>0 ? valeurs[0] : "",valeurs.length()>1 ? valeurs[1] : ""));
            else if(vnom=="ADR") contact->ajouterChamp(tr("adresse"),Contact::adresse(parseString(valeurs[2])));
            else if(vnom=="NOTE")
            {
                while((ligne=flux.readLine())!="END:VCARD") valeur+=ligne;
                contact->ajouterChamp(tr("note"),Contact::note(parseString(valeur)));
                if(!(contact->aNom())) contact->ajouterChamp(tr("nom"),kind=="individual" ? Personne::gnom("","") : Organisme::gnom("",""));
                ajouterContact(contact);
                contact=NULL;
            }
            else if(vnom=="TEL") contact->ajouterChamp(tr("tel"),Contact::tel(valeur));
            else if(vnom=="PHOTO") contact->ajouterChamp(tr("photo"),Personne::photo(valeur));
            else if(vnom=="LOGO") contact->ajouterChamp(tr("logo"),Organisme::logo(valeur));
            else if(vnom=="ORG") contact->ajouterChamp(tr("organisation"),Personne::organisation(valeur));
            else if(vnom=="MEMBER") contact->ajouterChamp(tr("membre"),Organisme::membre(valeurs.length()>1 ? valeurs[1] : "",valeurs.length()>0 ? valeurs[0] : ""));
            else if(vnom=="EMAIL")
            {
                Email * e=new Email();
                e->fromString(valeur);
                contact->ajouterChamp(tr("mail"),e);
            }
            else if(vnom=="BDAY") contact->ajouterChamp(tr("date de naissance"),Contact::date(valeur));
            //else if(vnom=="FN") 1; // que faire ????
            else if(vnom=="URL") contact->ajouterChamp(tr("url"),Contact::url(valeur));
//            else std::cout<<ligne.toStdString()<<"\n";
        }
    }
    std::for_each(mContacts.begin(),mContacts.end(),essayerEncore);
    fichier.close();
}


void Contacts::enregistrer(QString nomFichier) const
{
    QFile fichier(nomFichier);
    fichier.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream flux(&fichier);
    for (int i = 0; i < mContacts.size(); ++i)
    {
        flux<<"BEGIN:VCARD\n";
        flux<<"VERSION:4.0\n";
        Contact * contact=mContacts[i];
        flux<<"KIND:"<<(QString(contact->metaObject()->className())=="Personne" ? "individual" : "organism")<<"\n";
        const Champ * champ=NULL;
        if((champ=(*contact)[tr("nom")]))
        {
            flux<<"FN:"<<champ->toString()<<"\n";
            flux<<"N:"<<champ->toVCard()<<"\n";
        }
        if((champ=(*contact)[tr("adresse")])) flux<<"ADR:"<<unParseString(champ->toVCard())<<"\n";
        if((champ=(*contact)[tr("tel")])) flux<<"TEL:"<<champ->toVCard()<<"\n";
        if((champ=(*contact)[tr("mail")])) flux<<"EMAIL:"<<champ->toVCard()<<"\n";
        if((champ=(*contact)[tr("date de naissance")])) flux<<"BDAY:"<<champ->toVCard()<<"\n";
        if((champ=(*contact)[tr("url")])) flux<<"URL:"<<champ->toVCard()<<"\n";
        if((champ=(*contact)[tr("photo")]))flux<<"PHOTO:"<<champ->toVCard()<<"\n";
        if((champ=(*contact)[tr("organisation")]))flux<<"ORG:"<<champ->toVCard()<<"\n";
        if((champ=(*contact)[tr("membre")]))flux<<"MEMBER:"<<champ->toVCard()<<"\n";
        if((champ=(*contact)[tr("logo")]))flux<<"LOGO:"<<champ->toVCard()<<"\n";
        if((champ=(*contact)[tr("note")])) flux<<"NOTE:"<<unParseString(champ->toVCard())<<"\n";
        flux<<"END:VCARD\n";
    }
    fichier.close();
}


void Contacts::trier()
{
    std::stable_sort(mContacts.begin(), mContacts.end(), *mComp); // ne marche pas avec un std::sort , grand mystère
}

// n'existe que dans c++11 (qui n'est pas disponible sur la yaka)
template <class InputIterator, class OutputIterator, class UnaryPredicate>
  OutputIterator copy_if (InputIterator first, InputIterator last,
                          OutputIterator result, UnaryPredicate pred)
{
  while (first!=last) {
    if (pred(*first)) {
      *result = *first;
      ++result;
    }
    ++first;
  }
  return result;
}

Contacts * Contacts::rechercher(Search *search) const
{
    Contacts * nContacts=new Contacts();
    copy_if(mContacts.begin(), mContacts.end(),std::inserter(nContacts->mContacts,nContacts->mContacts.begin()), *search);
    return nContacts;
}
