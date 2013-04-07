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
#include "adresse.h"
#include "nom.h"
#include "tel.h"
#include "image.h"
#include "membre.h"
#include <QDomElement>
#include <QApplication>
#include <QTranslator>
#include "grandtexte.h"

Contacts::Contacts(QString locale, QTranslator *translator, QObject *parent) :
    QObject(parent),mLocale(locale),mTranslator(translator)
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
    return s.replace("\\n","\n").replace("\\,",",").replace("\\\"","\"").replace("\\:",":");
}

QString unParseString(QString s)
{
    return s.replace("\n","\\n").replace(",","\\,").replace("\"","\\\"").replace(":","\\:");
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

void Contacts::charger(QString nomFichier, QString type)
{
    if(type=="vCard") chargerVCard(nomFichier);
    else if(type=="XML") chargerXML(nomFichier);
}

Champ * qDomElementToChamp(QDomElement & unElement,bool dansPersonne)
{
    Champ * champ=NULL;
    Structure * structure=NULL;
    if(unElement.tagName() == "Adresse") structure=new Adresse();
    else if(unElement.tagName() == "Card") champ=new Card(dansPersonne);
    else if(unElement.tagName() == "Email") structure=new Email();
    else if(unElement.tagName() == "Enum") champ=new Enum();
    else if(unElement.tagName() == "Image") structure=new Image();
    else if(unElement.tagName() == "Loc") champ=new Loc();
    else if(unElement.tagName() == "Membre") structure=new Membre();
    else if(unElement.tagName() == "Nom") structure=new Nom();
    else if(unElement.tagName() == "Structure") structure=new Structure();
    else if(unElement.tagName() == "Tel") structure=new Tel();
    else if(unElement.tagName() == "Texte") champ=new Texte();
    else if(unElement.tagName() == "GrandTexte") champ=new GrandTexte();
    else if(unElement.tagName() == "Timestamp") champ=new Timestamp();
    else if(unElement.tagName() == "Url") champ=new Url();

    if(unElement.tagName() == "Adresse" || unElement.tagName() == "Email" || unElement.tagName() == "Image"
        || unElement.tagName() == "Membre"  || unElement.tagName() == "Nom" || unElement.tagName() == "Tel" || unElement.tagName() == "Structure")
    {
        QDomElement unElement2 = unElement.firstChildElement();
        while(!unElement2.isNull())
        {
            structure->ajouterChamp(unElement2.attribute("nomChamp"),qDomElementToChamp(unElement2,dansPersonne));
            unElement2 = unElement2.nextSiblingElement();
        }
        champ=structure;
    }
    else champ->fromString(unElement.text().trimmed());
    return champ;
}

void Contacts::vider()
{
    mContacts.clear();
}

void Contacts::chargerXML(QString nomFichier)
{
    mContacts.clear();
    QFile fichier(nomFichier);
    fichier.open(QFile::ReadOnly | QFile::Text);
    QDomDocument doc;
    doc.setContent(&fichier, false);
    QDomElement racine = doc.documentElement();
    racine = racine.firstChildElement();

    QApplication::removeTranslator(mTranslator);

    mLocale=racine.text();
    mTranslator=new QTranslator();
    mTranslator->load(QString(":/rcontact_") + mLocale);
    QApplication::installTranslator(mTranslator);
    racine = racine.nextSiblingElement();

    while(!racine.isNull())
    {
        Contact * contact=NULL;
        if(racine.tagName() == "Personne") contact=new Personne();
        else if(racine.tagName() == "Organisme") contact=new Organisme();

        QDomElement unElement = racine.firstChildElement();
        while(!unElement.isNull())
        {
            contact->ajouterChamp(unElement.attribute("nomChamp"),qDomElementToChamp(unElement,racine.tagName() == "Personne"));
            unElement = unElement.nextSiblingElement();
        }
        racine = racine.nextSiblingElement();
        ajouterContact(contact);
        contact=NULL;
    }
    std::for_each(mContacts.begin(),mContacts.end(),essayerEncore);
    fichier.close();
}

void Contacts::chargerVCard(QString nomFichier)
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
        QStringList types;
        if(noms.length()>1)
        {
            QStringList tt=noms[1].split("=");
            if(tt.length()>1 && tt[0]=="TYPE")
            {
                types=tt[1].split(",");
            }
        }
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
//            the Family Name, Given Name, Additional Names, Honorific
//               Prefixes, and Honorific Suffixes
            else if(vnom=="N") contact->ajouterChamp(tr("nom"),kind=="individual" ? Personne::gnom(valeurs.length()>0 ? parseString(valeurs[0]) : "",valeurs.length()>1 ? parseString(valeurs[1]) : "",
                                                                                                   valeurs.length()>3 ? parseString(valeurs[3]) : "",valeurs.length()>2 ? parseString(valeurs[2]) : "")
                                                                                  : Organisme::gnom(valeurs.length()>0 ? parseString(valeurs[0]) : "",valeurs.length()>1 ? parseString(valeurs[1]) : ""));
//            the post office box; the extended address; the street
//               address; the locality (e.g., city); the region (e.g., state or
//               province); the postal code; the country name
            else if(vnom=="ADR") contact->ajouterChamp(tr("adresse"),Contact::adresse(valeurs.length()>2 ? parseString(valeurs[2]) : "",valeurs.length()>5 ?
                                                                                          valeurs[5] : "",valeurs.length()>3 ? valeurs[3] : "",valeurs.length()>4 ?  valeurs[4] : ""
                                                                                                                                                                     ,valeurs.length()>6 ? valeurs[6] : "",types.contains("home",Qt::CaseInsensitive) ? tr("home") : tr("work")));
            else if(vnom=="NOTE")
            {
                while((ligne=flux.readLine())!="END:VCARD") valeur+=ligne;
                contact->ajouterChamp(tr("note"),Contact::note(parseString(valeur)));
                if(!(contact->aNom())) contact->ajouterChamp(tr("nom"),kind=="individual" ? Personne::gnom("","") : Organisme::gnom("",""));
                ajouterContact(contact);
                contact=NULL;
            }
            else if(vnom=="TEL") contact->ajouterChamp(tr("tel"),Contact::tel(valeur,
                                                                              types.contains("home",Qt::CaseInsensitive) ? tr("home") : tr("work"),
                                                                              types.contains("cell",Qt::CaseInsensitive) ? tr("cellulaire") : tr("fixe"),
                                                                              types.contains("data",Qt::CaseInsensitive) ? tr("data") : tr("voice")
                                                                              ));
            else if(vnom=="PHOTO") contact->ajouterChamp(tr("photo"),Personne::photo(parseString(valeur),types.contains("JPEG",Qt::CaseInsensitive) ? "JPEG" : (types.contains("PNG",Qt::CaseInsensitive) ? "PNG" : (types.contains("GIF",Qt::CaseInsensitive) ? "GIF" : "JPEG"))));
            else if(vnom=="LOGO") contact->ajouterChamp(tr("logo"),Organisme::logo(parseString(valeur),types.contains("JPEG",Qt::CaseInsensitive) ? "JPEG" : (types.contains("PNG",Qt::CaseInsensitive) ? "PNG" : (types.contains("GIF",Qt::CaseInsensitive) ? "GIF" : "JPEG"))));
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
            else if(vnom=="URL") contact->ajouterChamp(tr("url"),Contact::url(parseString(valeur)));
//            else std::cout<<ligne.toStdString()<<"\n";
        }
    }
    std::for_each(mContacts.begin(),mContacts.end(),essayerEncore);
    fichier.close();
}


void Contacts::enregistrer(QString nomFichier,QString type) const
{
    if(type=="vCard") enregistrerEnVCard(nomFichier);
    else if(type=="XML") enregistrerEnXML(nomFichier);
}

void Contacts::enregistrerEnXML(QString nomFichier) const
{
    QFile fichier(nomFichier);
    fichier.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream flux(&fichier);
    flux<<"<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
    flux<<"<Contacts>";
    flux<<"<lang>"+mLocale+"</lang>";
    for (int i = 0; i < mContacts.size(); ++i)
    {
        flux<<"<"+QString(mContacts[i]->metaObject()->className())+">";
        flux<<mContacts[i]->toXML();
        flux<<"</"+QString(mContacts[i]->metaObject()->className())+">";
    }
    flux<<"</Contacts>";
    fichier.close();
}

void Contacts::enregistrerEnVCard(QString nomFichier) const
{
    QFile fichier(nomFichier);
    fichier.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream flux(&fichier);
    for (int i = 0; i < mContacts.size(); ++i) flux<<mContacts[i]->toVCard();
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
    Contacts * nContacts=new Contacts(mLocale,mTranslator);
    copy_if(mContacts.begin(), mContacts.end(),std::inserter(nContacts->mContacts,nContacts->mContacts.begin()), *search);
    return nContacts;
}
