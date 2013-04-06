/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef TIMESTAMP_H
#define TIMESTAMP_H
#include <ctime>
#include "champ.h"

/**
 * @brief La classe Timestamp représente la date de modification du contact
 * Ce n'est pas un vrai champ dans le sens où il est automatiquement modifié, mais est enregistré en tant que tel.
 */
class Timestamp : public Champ
{
    Q_OBJECT
public:
    /**
     * @brief Le constructeur par défaut
     * @param s La valeur par défaut (utilise fromString pour convertir la QString en le type approprié)
     */
    Timestamp(const QString s="",QObject * parent=0);
    /**
     * @brief L'opérateur de comparaison
     */
    bool operator==(const Timestamp & c) const;
    /**
     * @brief toString convertit l'objet en format lisible
     * @return une QString contenant un format lisible du champ
     */
    QString toString() const;
    /**
     * @brief fromString convertit un QString en Timestamps
     * @param s La QString à convertir
     * @return true si la conversion a réussi, false sinon
     */
    bool fromString(const QString s);

    /**
     * @brief toVariant convertit l'objet en QVariant
     * @return Un QVariant qui décrit exactement l'objet
     */
    virtual QVariant toVariant();

    /**
     * @brief fromVariant convertit un QVariant en Timestamp
     * @param v Le QVariant à convertir
     * @return true si la conversion a réussi
     */
    virtual bool fromVariant(const QVariant v);

    /**
     * @brief toVCard convertit le champ en vCard
     * @return Un QString contenant la conversion
     */
    QString toVCard() const;

    /**
     * @brief toXML converti le champ en XML
     * @return Un QString contenant la conversion
     */

    QString toXML() const;

private:
    /**
     * @brief mT est le timestamp au moment de la dernière modification
     */
    time_t mT;
};

#endif // TIMESTAMP_H
