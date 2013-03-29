#include "structureoutexte.h"

StructureOuTexte::StructureOuTexte(QObject *parent) :
    Structure(parent)
{
}


QVariant StructureOuTexte::toVariant()
{
    return QVariant::fromValue(this);
}

bool StructureOuTexte::fromVariant(const QVariant v)
{
    mChamps=v.value<StructureOuTexte*>()->mChamps;
    emit dataChanged();
    return true;
}
