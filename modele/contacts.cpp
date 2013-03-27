#include "contacts.h"
#include <QFile>
#include <QTextStream>
#include "structure.h"
#include "texte.h"
#include "personne.h"
#include "organisme.h"
#include <iostream>
#include <algorithm>

Contacts::Contacts(QObject *parent) :
    QObject(parent)
{
}


void Contacts::ajouterContact(Contact * contact)
{
    mContacts<<contact;
}

void Contacts::ajouterContact()
{
    Contact * nouveau=Personne::creerDefaut();
    ajouterContact(nouveau);
}

void Contacts::supprimerContact(const int n)
{
    mContacts.removeAt(n);
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
                if(!(contact->aNom())) contact->ajouterChamp("nom",Personne::gnom("",""));
                ajouterContact(contact);
                contact=NULL;
            }
            else if(vnom=="N") contact->ajouterChamp("nom",Personne::gnom(valeurs.length()>0 ? valeurs[0] : "",valeurs.length()>1 ? valeurs[1] : ""));
            else if(vnom=="ADR") contact->ajouterChamp("adresse",Contact::adresse(parseString(valeurs[2])));
            else if(vnom=="NOTE")
            {
                while((ligne=flux.readLine())!="END:VCARD") valeur+=ligne;
                contact->ajouterChamp("note",Contact::note(parseString(valeur))); // pb avec les notes multi lignes
                if(!(contact->aNom())) contact->ajouterChamp("nom",Personne::gnom("",""));
                ajouterContact(contact);
                contact=NULL;
            }
            else if(vnom=="TEL") contact->ajouterChamp("tel",Contact::tel(valeur));
            else if(vnom=="EMAIL") contact->ajouterChamp("mail",Contact::email(valeur));
            else if(vnom=="BDAY") contact->ajouterChamp("date de naissance",Contact::date(valeur));
            else if(vnom=="FN") 1; // que faire ????
            else if(vnom=="URL") contact->ajouterChamp("url",Contact::url(valeur));
//            else std::cout<<ligne.toStdString()<<"\n";
        }
    }
}

void Contacts::enregistrer(QString nomFichier) const
{

}


void Contacts::trier(bool ordre, QString critereTri)
{
    Comp comp(ordre,critereTri);
    std::stable_sort(mContacts.begin(), mContacts.end(), comp); // ne marche pas avec un std::sort , grand mystère
}
