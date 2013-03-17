#include "controleur.h"
#include "modele/modeleaffichercontact.h"
#include "modele/modelelistecontacts.h"
#include "modele/contact.h"
#include "modele/texte.h"
#include "modele/structure.h"

Controleur::Controleur(QObject *parent) :
    QObject(parent)
{
    ModeleListeContacts * modeleListeContacts=new ModeleListeContacts(mContacts);
    mVue.setModeleListeContacts(modeleListeContacts);
    connect(&mVue,SIGNAL(contactActive(QModelIndex)),this,SLOT(afficherContact(QModelIndex)));
    connect(&mVue,SIGNAL(contactSupprime(QModelIndex)),this,SLOT(supprimerContact(QModelIndex)));



    // exemples (voués à disparaitre grâce à l'ajout et à l'import)
    Texte * valeur1=new Texte("valeur1");
    Texte * valeur2=new Texte("valeur2");

    Contact * contact1=new Contact();
    contact1->ajouterChamp("champ1",valeur1);
    contact1->ajouterChamp("champ2",valeur2);
    Contact * contact2=new Contact();
    Structure * nom=new Structure();
    nom->ajouterChamp("Nom",new Texte("Roussel"));
    nom->ajouterChamp("Prénom",new Texte("David"));
    contact2->ajouterChamp("nom",nom);

    mContacts.ajouterContact(contact1);
    mContacts.ajouterContact(contact2);
}

void Controleur::afficherContact(QModelIndex index)
{
    mVue.setModeleAfficherContact(new ModeleAfficherContact(mContacts[index.row()]));
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
