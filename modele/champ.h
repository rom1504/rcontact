#ifndef CHAMP_H
#define CHAMP_H

#include <QString>
#include <QVariant>

/**
 * @brief La classe Champ est la classe abstraite mère de toutes les classes symbolisant des champs de formulaire
 */
class Champ
{
public:
    /**
     * @brief Cette implémentation permet de renvoyer false par défaut quand on compare deux champs
     * Les champs comparables sont seulement les champs qui on le même type, l'opérateur de comparaison générique renvoie donc false puis est surchargé dans chaque fille
     * @return false
     */
    virtual bool operator==(const Champ &) const;
    /**
     * @brief toString convertis l'objet en format lisible
     * @return une QString contenant un format lisible du champ
     */
    virtual QString toString() const = 0;
    /**
     * @brief fromString convertis un QString en Champ
     * Elle n'est pas implémentée pour toutes les filles.
     * @return true si la conversion a réussi, false sinon
     */
    virtual bool fromString(const QString)= 0;

    virtual QVariant toVariant() const;
    virtual bool fromVariant(const QVariant v);
    virtual ~Champ();
};

#endif // CHAMP_H
