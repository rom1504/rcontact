#ifndef STRUCTURE_H
#define STRUCTURE_H

#include "champ.h"
#include <QMultiMap>

/**
 * @brief La classe Structure représente un champ structuré (qui contient une liste de champs)
 */
class Structure : public Champ
{
public:
    /**
     * @brief Le constructeur par défaut
     */
    Structure();
    /**
     * @brief ajouterChamp ajoute un champ dans la structure.
     * Si le nom renseigné n'existe pas, il créer un champ portant ce nom, sinon il en augmente l'arité
     * @param nomChamp Le nom du champ à ajouter
     * @param valeurChamp Un pointeur vers la valeur par défaut du champ
     */
    void ajouterChamp(const QString & nomChamp,Champ * valeurChamp);
    /**
     * @brief supprimerChamp supprime un champ dans la structure
     * @param nomChamp La nom du champ à supprimer
     * @param valeurChamp Un pointeur vers la valeur du champ à supprimer
     * @return le nombre de champs supprimés
     */
    int supprimerChamp(const QString & nomChamp, Champ *valeurChamp);
    /**
     * @brief L'opérateur de comparaison
     */
    bool operator==(const Structure & c) const;
    /**
     * @brief toString convertis l'objet en format lisible
     * @return une QString contenant un format lisible du champ
     */
    QString toString() const;
    /**
     * @brief fromString convertis un QString en Structure
     * @param s La QString à convertir
     * @return true si la conversion a réussi, false sinon
     */
    bool fromString(const QString s);
    ~Structure();

private:
    /**
     * @brief mChamps contient la liste des champs contenu dans la structure
     */
    QMultiMap<QString,Champ*> mChamps;
};

#endif // STRUCTURE_H
