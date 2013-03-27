#ifndef COMP_H
#define COMP_H

#include <cstdlib>
#include <functional>
#include "contact.h"

/**
 * @brief La class Comp est un foncteur permettant de comparer les Contact (pour les trier).
 * On implémente un foncteur et pas un surcharge de operator< dans Contact parce que les paramètres sont de pointeurs, pas des Contact
 */
class Comp: public std::binary_function<Contact*,Contact*,bool>
{
public:
    /**
     * @brief Le constructeur par défaut
     * @param ordre true pour ordre ascendant, et false prou ordre descendant
     * @param critereTri Le nom du champ servant de critère de comparaison
     */
    Comp(bool ordre,QString critereTri);

    /**
     * @brief operator () compare a et b selon le critère et l'odre passés en paramètre au constructeur
     * Si un des deux contacts
     * @param a Un pointeur vers le Contact gauche
     * @param b Un pointeur vers le Contact droit
     * @return true si a est plus petit (plus grand si ordre vaut false) que b selon le critère passé en paramètre, false sinon
     */
    bool operator()(Contact * a,Contact * b);

private:
    /**
     * @brief mOrdre est l'odre de comparaison.
     * Si mOrdre est à true, la comparaison est ascendante (équivaut à un '<').
     * Si mOrdre est à false, la comparaison est descendante (équivaut à un '>')
     */
    bool mOrdre;

    /**
     * @brief mCritereTri est le nom du champ dont on compare les valeurs
     */
    QString mCritereTri;
};

#endif // COMP_H
