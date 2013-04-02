/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef SEARCH_H
#define SEARCH_H

#include <functional>
#include "contact.h"

/**
 * @brief La classe Search est un foncteur pour la recherche
 */
class Search : public std::unary_function<Contact*,bool>
{
public:
    /**
     * @brief Constructeur du foncteur
     * @param nom Le nom du contact à trouver
     * @param c Vaut true si la recherche doit etre sensible à la casse
     * @param personne Vaut true si on cherche une personne
     * @param organisme Vaut true si on cherche un organisme
     */
    Search(QString nom,bool c,bool personne,bool organisme);
    /**
     * @brief Appel du foncteur
     * @param c Le contact à vérifier
     * @return true si le contact passé en paramètre correspond au nom donné lors de la construction
     */
    bool operator()(Contact * c) const;
private:
    /**
     * @brief mNom est le nom du contact à trouver
     */
    QString mNom;
    /**
     * @brief mCase vaut true si la recherche est sensible à la casse
     */
    bool mCase;
    /**
     * @brief mPersonne vaut true si on cherche une personne
     */
    bool mPersonne;
    /**
     * @brief mOrganisme vaut true si on cherche un organisme
     */
    bool mOrganisme;
};
#endif // SEARCH_H
