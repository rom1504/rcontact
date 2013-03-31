#include "nom.h"
#include <QStringList>
#include "texte.h"

Nom::Nom(QObject *parent) :
    StructureOuTexte(parent)
{
}

/**
 * @brief toString convertit l'objet en format lisible
 * @return une QString contenant un format lisible du champ
 */
QString Nom::toString() const
{
    return (avoirChamp(tr("Préfixe"))+" "+avoirChamp(tr("Prénom"))+" "+avoirChamp(tr("Nom"))+" "+avoirChamp(tr("Surnom"))).trimmed();
}

/**
 * @brief fromString convertit un QString en Structure
 * @param s La QString à convertir
 * @return true si la conversion a réussi, false sinon
 */
bool Nom::fromString(const QString s)
{
    QStringList l=s.split(" ");
    vider();
    ajouterChamp(tr("Préfixe"),new Texte(l.length()>=3 ? l.takeFirst() : ""));
    ajouterChamp(tr("Prénom"),new Texte(l.length()>=1 ? l.takeFirst() : ""));
    ajouterChamp(tr("Nom"),new Texte(l.length()>=1 ? l.takeFirst() : ""));
    ajouterChamp(tr("Surnom"),new Texte(l.join(" ")));
    return true;
}

QString Nom::toVCard() const
{
    return avoirChamp(tr("Nom"))+";"+avoirChamp(tr("Prénom"))+";"+avoirChamp(tr("Préfixe"))+";"+avoirChamp(tr("Surnom"))+";";// ?
}
