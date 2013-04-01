#include "membre.h"

Membre::Membre(QObject *parent) :
    Structure(parent)
{
}

QString Membre::toVCard() const
{
    return avoirChamp(tr("card"))+";"+avoirChamp(tr("fonction"));
}
