/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef STRUCTUREOUTEXTE_H
#define STRUCTUREOUTEXTE_H

#include "structure.h"

/**
 * @brief La classe StructureOuTexte représente un champ soit structuré, soit textuel
 */
class StructureOuTexte : public Structure
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur par défaut
     */
    explicit StructureOuTexte(QObject *parent = 0);

    /**
     * @brief toVariant convertit le champ en QVariant
     * @return Un QVariant représentant le champ
     */
    QVariant toVariant();

    /**
     * @brief fromVariant importe un champ depuis un QVariant
     * @param v Le QVariant à convertir en champ
     * @return true si la conversion a réussi
     */
    virtual bool fromVariant(const QVariant v);
    
signals:
    
public slots:
    
};

Q_DECLARE_METATYPE (StructureOuTexte*)

#endif // STRUCTUREOUTEXTE_H
