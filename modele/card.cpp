#include "card.h"

Card::Card(const Contact *contact) : mContact(contact)
{

}


bool Card::operator==(const Card & c) const
{
    return (*mContact)==*(c.mContact);
}

QString Card::toString() const
{
    return mContact->nom();
}

bool Card::fromString(const QString)
{
    return false;
}

Card::~Card()
{

}
