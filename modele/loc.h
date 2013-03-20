#ifndef LOC_H
#define LOC_H

#include "champ.h"

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
    Loc(const QString s="");
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
    ~Loc();
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

#endif // LOC_H
