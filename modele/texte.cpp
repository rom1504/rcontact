#include "texte.h"

Texte::Texte(const QString value) : mValue(value)
{

}


bool Texte::operator==(const Texte & t) const
{
    return mValue == t.mValue;
}


bool Texte::operator==(const Champ & t) const
{
    return mValue == t.toString();
}

QString Texte::toString() const
{
    return mValue;
}

void Texte::fromString(const QString s)
{
    mValue=s;
}

Texte::~Texte()
{

}
