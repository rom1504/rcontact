/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef TEL_H
#define TEL_H

#include "structureoutexte.h"

/**
 * @brief La classe Tel représente
 */
class Tel : public StructureOuTexte
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur par défaut
     */
    explicit Tel(QObject *parent = 0);
    
    /**
     * @brief toString convertit l'objet en format lisible
     * @return une QString contenant un format lisible du champ
     */
    QString toString() const;
    /**
     * @brief fromString convertit un QString en Structure
     * @param s La QString à convertir
     * @return true si la conversion a réussi, false sinon
     */
    bool fromString(const QString s);


    /**
     * @brief toVCard fait l'export en vCard
     * @return une QString qui contient le vCard
     */

    QString toVCard() const;

signals:
    
public slots:
    
};

#endif // TEL_H
