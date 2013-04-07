/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef NOM_H
#define NOM_H

#include "structureoutexte.h"

/**
 * @brief La classe Nom représente un champ décrivant le nom d'un contact
 */
class Nom : public StructureOuTexte
{
    Q_OBJECT
public:

    /**
     * @brief Constructeur par défaut
     */
    explicit Nom(QObject *parent = 0);

    explicit Nom(const QString nom, const QString prenom, const QString prefixe, const QString surnom);

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
     * @brief toVCard convertis le nom en format vCard
     */
    QString toVCard() const;
    
signals:
    
public slots:

private:
    
};

#endif // NOM_H
