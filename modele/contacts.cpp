#include "contacts.h"

Contacts::Contacts(QObject *parent) :
    QObject(parent)
{
}


void Contacts::ajouterContact(Contact * contact)
{
    mContacts<<contact;
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
