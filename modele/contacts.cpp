#include "contacts.h"

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
