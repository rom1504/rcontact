#include "texte.h"

Texte::Texte(const QString value, QObject *parent) : Champ(parent),mValue(value)
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
    emit dataChanged();
    return true;
}



void Texte::setValue(const QString value)
{
    mValue=value;
}

QString Texte::value() const
{
    return mValue;
}
