#include "tel.h"
#include "texte.h"
#include "enum.h"

Tel::Tel(QObject *parent) :
    StructureOuTexte(parent)
{
}

Tel::Tel(const QString numero, const QString type, const QString typeTel, const QString typeDonnees)
{
    ajouterChamp(tr("type"),new Enum(type));
    ajouterChamp(tr("type tel"),new Enum(typeTel));
    ajouterChamp(tr("type données"),new Enum(typeDonnees));
    ajouterChamp(tr("n°"),new Texte(numero));
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
