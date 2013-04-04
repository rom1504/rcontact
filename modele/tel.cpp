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

QString Tel::toVCard() const
{
    return ";TYPE="+avoirChamp(tr("type"))+","+(avoirChamp(tr("type tel"))==tr("cellulaire") ? "cell" : "pref")+","+avoirChamp(tr("type données"))+":"+avoirChamp(tr("n°"));
}
