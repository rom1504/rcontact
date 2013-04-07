#include "card.h"
#include "contact.h"
#include "search.h"
#include "contacts.h"

Contacts * Card::mContacts;

Card::Card(bool appartientAUnePersonne, QString nom, QObject * parent) : Champ(parent),mContact(NULL),mAppartientAUnePersonne(appartientAUnePersonne)
{
    fromString(nom);
}


QString Card::toString() const
{
    return mContact==NULL ? "" : mContact->nom();
}

bool Card::fromString(const QString nom)
{
    mTempNom=nom;
    if(nom=="") return false;
    Contacts * contacts=mContacts->rechercher(new Search(nom,false,!mAppartientAUnePersonne,mAppartientAUnePersonne));
    if(contacts->nombre()>=1)
    {
        mContact=(*contacts)[0];
        emit dataChanged();
        return true;
    }
    return false;
}

QVariant Card::image()
{
    if(mContact!=NULL) return mContact->image();
    return QVariant();
}

void Card::essayerEncore()
{
    fromString(mTempNom);
}
