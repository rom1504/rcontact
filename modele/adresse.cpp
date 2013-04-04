#include "adresse.h"
#include <QStringList>
#include "texte.h"
#include "loc.h"
#include "enum.h"

Adresse::Adresse(QObject *parent) :
    StructureOuTexte(parent)
{
}

QString Adresse::toString() const
{
    return (avoirChamp(tr("rue"))+" "+avoirChamp(tr("zipcode"))+" "+avoirChamp(tr("localité"))+" "+avoirChamp(tr("Région"))+" "+avoirChamp(tr("pays"))+" "+avoirChamp(tr("géo"))).trimmed();
}

QString Adresse::toVCard() const
{
    return ";;"+avoirChamp(tr("rue"))+";;;;";
}

bool Adresse::fromString(const QString s)
{
    if(toString()!=s)
    {
        QStringList l=s.split(" ");
        vider();

        // à améliorer ou bien repasser en juste Structure ?
        ajouterChamp(tr("rue"),new Texte(s));
        ajouterChamp(tr("type"),new Enum("work"));
        ajouterChamp(tr("zipcode"),new Texte(""));
        ajouterChamp(tr("localité"),new Texte(""));
        ajouterChamp(tr("Région"),new Texte(""));
        ajouterChamp(tr("pays"),new Texte(""));
        ajouterChamp(tr("geo"),new Loc());
        return true;
    }
    return false;
}

