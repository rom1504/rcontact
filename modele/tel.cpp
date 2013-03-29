#include "tel.h"
#include "texte.h"

Tel::Tel(QObject *parent) :
    StructureOuTexte(parent)
{
}

/**
 * @brief toString convertit l'objet en format lisible
 * @return une QString contenant un format lisible du champ
 */
QString Tel::toString() const
{
    return (avoirChamp(tr("n°"))).trimmed();
}

/**
 * @brief fromString convertit un QString en Structure
 * @param s La QString à convertir
 * @return true si la conversion a réussi, false sinon
 */
bool Tel::fromString(const QString s)
{
    remplacer(tr("n°"),new Texte(s));
    return true;
}
