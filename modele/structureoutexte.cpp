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
    return Structure::fromVariant(QVariant::fromValue((Structure*)v.value<StructureOuTexte*>()));
}
