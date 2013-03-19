#include "controleur.h"
#include "modele/modeleaffichercontact.h"
#include "modele/modelelistecontacts.h"
#include "modele/contact.h"
#include "modele/texte.h"
#include "modele/structure.h"
#include "modele/url.h"
#include "modele/card.h"
#include "modele/loc.h"
#include "modele/timestamp.h"
#include "modele/enum.h"

Controleur::Controleur(QObject *parent) :
    QObject(parent)
{

    Enum::remplirEnums();
    ModeleListeContacts * modeleListeContacts=new ModeleListeContacts(mContacts);
    mVue.setModeleListeContacts(modeleListeContacts);
    connect(&mVue,SIGNAL(contactActive(QModelIndex)),this,SLOT(afficherContact(QModelIndex)));
    connect(&mVue,SIGNAL(contactEdite(QModelIndex)),this,SLOT(editerContact(QModelIndex)));
    connect(&mVue,SIGNAL(contactSupprime(QModelIndex)),this,SLOT(supprimerContact(QModelIndex)));



    // exemples (voués à disparaitre grâce à l'ajout et à l'import)
    Texte * valeur1=new Texte("valeur1");
    Texte * valeur2=new Texte("valeur2");

    Contact * contact1=new Contact();
    contact1->ajouterChamp("champ1",valeur1);
    contact1->ajouterChamp("champ2",valeur2);
    contact1->ajouterChamp("url",new Url("http://www.google.fr/"));
    contact1->ajouterChamp("achamp1",new Texte("test"));
    Structure * nom1=new Structure();
    nom1->ajouterChamp("Nom",new Texte("Beaumont"));
    nom1->ajouterChamp("Prénom",new Texte("Romain"));
    contact1->ajouterChamp("nom",nom1);
    Contact * contact2=new Contact();
    Structure * nom=new Structure();
    nom->ajouterChamp("Nom",new Texte("Roussel"));
    nom->ajouterChamp("Prénom",new Texte("David"));
    contact2->ajouterChamp("nom",nom);
    contact2->ajouterChamp("card",new Card(contact1));
    contact2->ajouterChamp("loc",new Loc("66.6,42.0"));
    contact2->ajouterChamp("date MAJ",new Timestamp("34343453"));

    contact2->ajouterChamp("test enum type site",new Enum("google"));

    mContacts.ajouterContact(contact1);
    mContacts.ajouterContact(contact2);
}

void Controleur::afficherContact(QModelIndex index)
{
    mVue.setModeleAfficherContact(new ModeleAfficherContact(mContacts[index.row()]));
}

void Controleur::editerContact(QModelIndex index)
{
    ModeleAfficherContact * model=new ModeleAfficherContact(mContacts[index.row()]);
    model->rendreEditable();
    mVue.setModeleEditerContact(model);
}

void Controleur::supprimerContact(QModelIndex index)
{
    mContacts.supprimerContact(index.row());
    mVue.setModeleAfficherContact(NULL);
}

void Controleur::run()
{
    mVue.show();
}
