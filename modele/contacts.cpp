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

void Contacts::ajouterContact()
{
    Contact * nouveau=Personne::creerDefaut();
    ajouterContact(nouveau);
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

void Contacts::changerTri(Comp * comp)
{
    mComp=comp;
    trier();
}

void Contacts::charger(QString nomFichier)
{

    mContacts.clear();
    QFile fichier(nomFichier);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);
    QString ligne;
    Contact * contact=NULL;
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
        QString version="";
        if(nom=="BEGIN" && valeur=="VCARD") contact=new Personne();
        else if(nom=="VERSION") version=valeur;
        else if(contact!=NULL)
        {
            if(nom=="END" && valeur=="VCARD")
            {
                if(!(contact->aNom())) contact->ajouterChamp(tr("nom"),Personne::gnom("",""));
                ajouterContact(contact);
                contact=NULL;
            }
            else if(vnom=="N") contact->ajouterChamp(tr("nom"),Personne::gnom(valeurs.length()>0 ? valeurs[0] : "",valeurs.length()>1 ? valeurs[1] : ""));
            else if(vnom=="ADR") contact->ajouterChamp(tr("adresse"),Contact::adresse(parseString(valeurs[2])));
            else if(vnom=="NOTE")
            {
                while((ligne=flux.readLine())!="END:VCARD") valeur+=ligne;
                contact->ajouterChamp(tr("note"),Contact::note(parseString(valeur))); // pb avec les notes multi lignes
                if(!(contact->aNom())) contact->ajouterChamp(tr("nom"),Personne::gnom("",""));
                ajouterContact(contact);
                contact=NULL;
            }
            else if(vnom=="TEL") contact->ajouterChamp(tr("tel"),Contact::tel(valeur));
            else if(vnom=="EMAIL") contact->ajouterChamp(tr("mail"),Contact::email(valeur));
            else if(vnom=="BDAY") contact->ajouterChamp(tr("date de naissance"),Contact::date(valeur));
            else if(vnom=="FN") 1; // que faire ????
            else if(vnom=="URL") contact->ajouterChamp(tr("url"),Contact::url(valeur));
//            else std::cout<<ligne.toStdString()<<"\n";
        }
    }
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
        Contact * contact=mContacts[i];
        const Champ * champ=NULL;
        if((champ=(*contact)[tr("nom")])) flux<<"N:"<<champ->toString()<<"\n"; // pas encore ça
        flux<<"END:VCARD\n";
    }
    fichier.close();
}


void Contacts::trier()
{
    std::stable_sort(mContacts.begin(), mContacts.end(), *mComp); // ne marche pas avec un std::sort , grand mystère
}

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
