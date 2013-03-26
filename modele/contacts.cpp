#include "contacts.h"
#include <QFile>
#include <QTextStream>
#include "structure.h"
#include "texte.h"

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
    Contact * nouveau=new Contact();
    nouveau->ajouterChamp("nom","nom");
    nouveau->ajouterChamp("sexe","sexe");
    nouveau->ajouterChamp("tel","tel");
    nouveau->ajouterChamp("adresse","adresse");
    nouveau->ajouterChamp("email","email");
    nouveau->ajouterChamp("date MAJ","date MAJ");
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
        QString nomChamp=(l.length()>1) ? l[0] : "";
        QString valeurChamp=(l.length()>2) ? l[1] : "";
        QStringList valeursChamp=valeurChamp.split(";");

        if(nomChamp=="BEGIN" && valeurChamp=="VCARD") contact=new Contact();
        if(nomChamp=="END" && valeurChamp=="VCARD" && contact!=NULL)
        {
            if(!(contact->aNom()))
            {
                Structure * structure=new Structure();
                structure->ajouterChamp("Préfixe",new Texte());
                if(valeursChamp.length()>0) structure->ajouterChamp("Nom",new Texte("nom"));
                if(valeursChamp.length()>1) structure->ajouterChamp("Prénom",new Texte("prénom"));
                structure->ajouterChamp("Surnom",new Texte());
                contact->ajouterChamp("nom",structure);
            }
            ajouterContact(contact);
        }
        if(nomChamp=="N"  && contact!=NULL)
        {
            Structure * structure=new Structure();

            structure->ajouterChamp("Préfixe",new Texte());
            structure->ajouterChamp("Nom",new Texte(valeursChamp.length()>0 ? valeursChamp[0] : ""));
            structure->ajouterChamp("Prénom",new Texte(valeursChamp.length()>1 ? valeursChamp[1] : ""));
            structure->ajouterChamp("Surnom",new Texte());
            contact->ajouterChamp("nom",structure);
        }
    }
}

void Contacts::enregistrer(QString nomFichier) const
{

}
