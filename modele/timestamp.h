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
public:
    /**
     * @brief Le constructeur par défaut
     * @param s La valeur par défaut (utilise fromString pour convertir la QString en le type approprié)
     */
    Timestamp(const QString s="");
    /**
     * @brief L'opérateur de comparaison
     */
    bool operator==(const Timestamp & c) const;
    /**
     * @brief toString convertis l'objet en format lisible
     * @return une QString contenant un format lisible du champ
     */
    QString toString() const;
    /**
     * @brief fromString convertis un QString en Timestamps
     * @param s La QString à convertir
     * @return true si la conversion a réussi, false sinon
     */
    bool fromString(const QString s);
    virtual QVariant toVariant() const;
    virtual bool fromVariant(const QVariant v);
private:
    /**
     * @brief mT est le timestamp au moment de la dernière modification
     */
    time_t mT;
};

#endif // TIMESTAMP_H
