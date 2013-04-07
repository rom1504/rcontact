#include "grandtexte.h"
#include <iostream>

GrandTexte::GrandTexte(const QString value,QObject *parent) :
    Texte(value,parent)
{
}

QVariant GrandTexte::toVariant()
{
    return QVariant::fromValue(this);
}

bool GrandTexte::fromVariant(const QVariant v)
{
    mValue=v.value<GrandTexte*>()->mValue;
    return true;
}
