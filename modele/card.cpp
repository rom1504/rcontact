#include "card.h"
#include "contact.h"

Card::Card(const Contact *contact) : mContact(contact)
{

}


bool Card::operator==(const Card & c) const
{
    return mContact!=NULL && c.mContact!=NULL && (*mContact)==*(c.mContact);
}

QString Card::toString() const
{
    return mContact==NULL ? "" : mContact->nom();
}

bool Card::fromString(const QString)
{
    return false;
}

Card::~Card()
{

}
