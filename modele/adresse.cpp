#include "adresse.h"
#include <QStringList>
#include "texte.h"
#include "loc.h"
#include "enum.h"

Adresse::Adresse(QObject *parent) :
    StructureOuTexte(parent)
{
}

/**
 * @brief toString convertit l'objet en format lisible
 * @return une QString contenant un format lisible du champ
 */
QString Adresse::toString() const
{
    return (avoirChamp(tr("rue"))+" "+avoirChamp(tr("zipcode"))+" "+avoirChamp(tr("localité"))+" "+avoirChamp(tr("Région"))+" "+avoirChamp(tr("pays"))+" "+avoirChamp(tr("géo"))).trimmed();
}

QString Adresse::toVCard() const
{
    return ";;"+avoirChamp(tr("rue"))+";;;;";
}

/**
 * @brief fromString convertit un QString en Structure
 * @param s La QString à convertir
 * @return true si la conversion a réussi, false sinon
 */
bool Adresse::fromString(const QString s)
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

