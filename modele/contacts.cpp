#include "contacts.h"
#include <QFile>
#include <QTextStream>
#include "structure.h"
#include "texte.h"
#include "personne.h"
#include "organisme.h"

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
        QStringList l=ligne.split(":");
        QString nomChamp=(l.length()>=1) ? l[0] : "";
        QStringList nomsChamp=nomChamp.split(";");
        QString vNomChamp=nomsChamp[0];
        QString valeurChamp=(l.length()>=2) ? l[1] : "";
        QStringList valeursChamp=valeurChamp.split(";");

        if(nomChamp=="BEGIN" && valeurChamp=="VCARD") contact=new Personne();
        if(contact!=NULL)
        {
            if(nomChamp=="END" && valeurChamp=="VCARD")
            {
                if(!(contact->aNom())) contact->ajouterChamp("nom",Personne::gnom("","","",""));
                ajouterContact(contact);
                contact=NULL;
            }
            else if(vNomChamp=="N") contact->ajouterChamp("nom",Personne::gnom("",valeursChamp.length()>0 ? valeursChamp[0] : "",valeursChamp.length()>1 ? valeursChamp[1] : "",""));
            else if(vNomChamp=="ADR") contact->ajouterChamp("adresse",Contact::adresse("home",valeursChamp[2],"","","",""));
        }
    }
}

void Contacts::enregistrer(QString nomFichier) const
{

}
