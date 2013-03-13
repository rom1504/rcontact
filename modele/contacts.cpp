#include "contacts.h"

Contacts::Contacts(QObject *parent) :
    QObject(parent)
{
}


void Contacts::ajouterContact(const Contact & contact)
{
    mContacts<<contact;;
    //mModeleListeContacts<<contact.champ("nom");
}

int Contacts::supprimerContact(const Contact & contact)
{
    return mContacts.removeAll(contact);
}
