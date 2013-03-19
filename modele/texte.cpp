#include "texte.h"

Texte::Texte(const QString value) : mValue(value)
{

}


bool Texte::operator==(const Texte & t) const
{
    return mValue == t.mValue;
}


QString Texte::toString() const
{
    return mValue;
}

bool Texte::fromString(const QString s)
{
    mValue=s;
    return true;
}

Texte::~Texte()
{

}
