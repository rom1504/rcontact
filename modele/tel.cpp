#include "tel.h"
#include "texte.h"

Tel::Tel(QObject *parent) :
    StructureOuTexte(parent)
{
}

QString Tel::toString() const
{
    return (avoirChamp(tr("n°"))).trimmed();
}

bool Tel::fromString(const QString s)
{
    remplacer(tr("n°"),new Texte(s));
    return true;
}
