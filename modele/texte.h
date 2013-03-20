#ifndef TEXTE_H
#define TEXTE_H

#include <QString>
#include "champ.h"

/**
 * @brief La classe Texte représente un champ contenant du texte
 */
class Texte : public Champ
{
public:
    /**
     * @brief Le constructeur par défaut
     * @param s La valeur par défaut (utilise fromString pour convertir la QString en le type approprié)
     */
    Texte(const QString value="");
    /**
     * @brief setValue modifie la valeur du texte contenu dan sla champ
     * @param value Le nouveau texte
     */
    void setValue(const QString value);
    /**
     * @brief value renvoie la valeur actuelle du champ
     * @return une QString dont la valeur est celle du texte du champ
     */
    QString value() const;
    /**
     * @brief L'opérateur de comparaison
     */
    virtual bool operator==(const Texte & t) const;
    /**
     * @brief toString convertis l'objet en format lisible
     * @return une QString contenant un format lisible du champ
     */
    QString toString() const;
    /**
     * @brief fromString convertis un QString en Texte
     * @param s La QString à convertir
     * @return true si la conversion a réussi, false sinon
     */
    bool fromString(const QString s);
    ~Texte();

protected:
    /**
     * @brief mValue La valeur du champ
     */
    QString mValue;
};

#endif // TEXTE_H
