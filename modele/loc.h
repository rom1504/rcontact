#ifndef LOC_H
#define LOC_H

#include "champ.h"
#include <QMetaType>

/**
 * @brief La classe Loc représente un champ décrivant une position géographique
 */
class Loc : public Champ
{
public:
    /**
     * @brief Le constructeur par défaut
     * @param s La valeur par défaut (utilise fromString pour convertir la QString en le type approprié)
     */
    Loc(const double latitude=0,const double longitude=0);
    /**
     * @brief L'opérateur de comparaison
     */
    bool operator==(const Loc & c) const;
    /**
     * @brief toString convertit l'objet en format lisible
     * @return une QString contenant un format lisible du champ
     */
    QString toString() const;
    /**
     * @brief fromString convertit un QString en Loc
     * @param s La QString à convertir
     * @return true si la conversion a réussi, false sinon
     */
    bool fromString(const QString s);

    /**
     * @brief latitude renvoie la latitude
     * @return La latitude
     */
    double latitude() const;

    /**
     * @brief longitude renvoie la longitude
     * @return La longitude
     */
    double longitude() const;

    /**
     * @brief toVariant convertit l'objet en QVariant
     * @return Un QVariant qui décrit exactement l'objet
     */
    QVariant toVariant() const;

    /**
     * @brief fromVariant convertit un QVariant en Loc
     * @param v Le QVariant à convertir
     * @return true si la conversion a réussi
     */
    bool fromVariant(const QVariant v);

private:
    /**
     * @brief mLatitude La latitude
     */
    double mLatitude;
    /**
     * @brief mLongitude La longitude
     */
    double mLongitude;
};

Q_DECLARE_METATYPE (Loc)

#endif // LOC_H
