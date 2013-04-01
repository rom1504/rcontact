#include "controleur.h"
#include "modele/modeleaffichercontact.h"
#include "modele/modelelistecontacts.h"
#include "modele/personne.h"
#include "modele/organisme.h"
#include "modele/texte.h"
#include "modele/structure.h"
#include "modele/url.h"
#include "modele/card.h"
#include "modele/loc.h"
#include "modele/timestamp.h"
#include "modele/enum.h"
#include "modele/nom.h"
#include "modele/tel.h"

Controleur::Controleur(QObject *parent) :
    QObject(parent)
{

    Enum::remplirEnums();
    mContacts=new Contacts();
    mContactsEntier=mContacts;
    Card::mContacts=mContactsEntier;
    ModeleListeContacts * modeleListeContacts=new ModeleListeContacts(*mContacts);
    mVue.setModeleListeContacts(modeleListeContacts);
    connect(&mVue,SIGNAL(contactActive(int)),this,SLOT(afficherContact(int)));
    connect(&mVue,SIGNAL(contactEdite(int)),this,SLOT(editerContact(int)));
    connect(&mVue,SIGNAL(rechercherContacts(Search *)),this,SLOT(rechercherContacts(Search *)));
    connect(&mVue,SIGNAL(finirLaRecherche()),this,SLOT(finirLaRecherche()));
    connect(&mVue,SIGNAL(enregistrerContacts(QString)),mContacts,SLOT(enregistrer(QString)));
    modeleListeContacts->charger("exemple.vcf");

    // exemples (voués à disparaitre grâce à l'ajout et à l'import)
//    Texte * valeur1=new Texte("valeur1");
//    Texte * valeur2=new Texte("valeur2");

//    Contact * contact1=new Personne();
//    Nom * n=new Nom();
//    Tel * t=new Tel();
//    Tel * s=new Tel();
//    t->ajouterChamp("n°",new Texte(""));
//    n->fromString("Romain Beaumont");
//    contact1->ajouterChamp("nom",n);
//    contact1->ajouterChamp("s",s);
//    mContacts->ajouterContact(contact1);

//    contact1->ajouterChamp("champ1",valeur1);
//    contact1->ajouterChamp("champ2",valeur2);
//    contact1->ajouterChamp("url",new Url("http://www.google.fr/"));
//    contact1->ajouterChamp("achamp1",new Texte("test"));
//    Structure * nom1=new Structure();
//    nom1->ajouterChamp("Nom",new Texte("Beaumont"));
//    nom1->ajouterChamp("Prénom",new Texte("Romain"));
//    contact1->ajouterChamp("nom",nom1);
//    Contact * contact2=new Personne();
//    Structure * nom=new Structure();
//    nom->ajouterChamp("Nom",new Texte("Roussel"));
//    nom->ajouterChamp("Prénom",new Texte("David"));
//    contact2->ajouterChamp("nom",nom);
//    contact2->ajouterChamp("card",new Card(contact1));
//    contact2->ajouterChamp("loc",new Loc(66.6,42.0));
//    contact2->ajouterChamp("date MAJ",new Timestamp("34343453"));

//    contact2->ajouterChamp("test enum type site",new Enum("google"));
//    contact2->ajouterChamp("test enum sexe",new Enum("homme"));

//    mContacts.ajouterContact(contact1);
//    mContacts.ajouterContact(contact2);
}

void Controleur::afficherContact(int index)
{
    mVue.setModeleAfficherContact(index==-1 || mContacts->nombre()<=index ? NULL : new ModeleAfficherContact((*mContacts)[index]));
}

void Controleur::editerContact(int index)
{
    ModeleAfficherContact * model=new ModeleAfficherContact((*mContacts)[index]);
    model->rendreEditable();
    mVue.setModeleEditerContact(model);
}

void Controleur::run()
{
    mVue.show();
}

void Controleur::rechercherContacts(Search *search)
{
    mContacts=mContactsEntier->rechercher(search);
    ModeleListeContacts * modeleListeContacts=new ModeleListeContacts((*mContacts));
    mVue.setModeleListeContacts(modeleListeContacts);
}

void Controleur::finirLaRecherche()
{
    mContacts=mContactsEntier;
    ModeleListeContacts * modeleListeContacts=new ModeleListeContacts((*mContacts));
    mVue.setModeleListeContacts(modeleListeContacts);
}
