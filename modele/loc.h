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
     * @brief toString convertis l'objet en format lisible
     * @return une QString contenant un format lisible du champ
     */
    QString toString() const;
    /**
     * @brief fromString convertis un QString en Loc
     * @param s La QString à convertir
     * @return true si la conversion a réussi, false sinon
     */
    bool fromString(const QString s);

    double latitude() const;
    double longitude() const;

    QVariant toVariant() const;
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
