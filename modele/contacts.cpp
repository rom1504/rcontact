#include "contacts.h"

Contacts::Contacts(QObject *parent) :
    QObject(parent)
{
}


void Contacts::ajouterContact(Contact * contact)
{
    mContacts<<contact;;
    emit dataChanged(mContacts.length()-1,mContacts.length()-1);
}

void Contacts::supprimerContact(const int n)
{
    mContacts.removeAt(n);
    emit dataChanged(0,mContacts.length()-1);
}

int Contacts::nombre() const
{
    return mContacts.length();
}

const Contact * Contacts::operator[](const int n) const
{
    return mContacts[n];
}
