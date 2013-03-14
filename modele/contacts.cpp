#include "contacts.h"

Contacts::Contacts(QObject *parent) :
    QObject(parent)
{
}


void Contacts::ajouterContact(const Contact & contact)
{
    mContacts<<contact;;
    emit dataChanged(mContacts.length()-1,mContacts.length()-1);
}

int Contacts::supprimerContact(const Contact & contact)
{
    int nb=mContacts.removeAll(contact);
    emit dataChanged(0,mContacts.length()-1);
    return nb;
}

int Contacts::nombre() const
{
    return mContacts.length();
}

const Contact & Contacts::operator[](const int n) const
{
    return mContacts[n];
}
