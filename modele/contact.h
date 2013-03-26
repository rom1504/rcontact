#ifndef CONTACT_H
#define CONTACT_H

#include "champ.h"
#include <QMultiMap>
#include <QString>
#include <QPair>

/**
 * @brief La classe Contact représente un contact enregistré, c'est à dire un multimap de champs.
 */
class Contact
{
public:
    /**
     * @brief Le constructeur par défaut de la classe
     */
    explicit Contact();
    /**
     * @brief Le constructeur de copie
     * @param c le Contact a copier
     */
    Contact(const Contact & c);

    ~Contact();

    /**
     * @brief ajouterChamp ajoute le champs libelé nomChamp avec la valeur valeurChamp
     * @param nomChamp Le nom du champ à ajouter (ex : "nom", "téléphone", ...)
     * @param valeurChamp La valeur du champ à ajouter
     */
    void ajouterChamp(const QString & nomChamp, Champ* valeurChamp);

    /**
     * @brief creerChamp créé un champ à partir de son nom et son type, et l'ajoute
     * @param nomChamp Le nom du champ à créer
     * @param type Le type du champ à créer
     */
    virtual void creerChamp(const QString & nomChamp, const QString& type)=0;


    /**
     * @brief supprimerChamp supprime le champ libelé nomChamp qui a la valeur valeurChamp
     * @param nomChamp Le nom du champ à supprimer
     * @param valeurChamp La valeur du champ à supprimer
     * @return le nombre de valeurs supprimées
     */
    int supprimerChamp(const QString & nomChamp, Champ * valeurChamp);

    int supprimerChamp(const int index);

    /**
     * @brief nombreValeurs
     * @return le nombre de valeur totales
     */
    int nombreValeurs() const;

    /**
     * @brief nom
     * @return Le nom du contact
     */
    QString nom() const;

    /**
     * @brief L'opérateur d'égalité
     */
    bool operator==(const Contact & c) const; // problème : ne sera pas utilisé dans le QMultiMap car ce sont des pointeurs qui sont stockés... : à vérifier...

    /**
     * @brief opérateur d'accès
     */
    const QPair<QString,Champ*> operator[](const int n) const;


private:
    /**
     * @brief mChamps est un multimap associant des libelés de champs (les QString) à des valeurs (les *Champ)
     */
    QMultiMap<QString,Champ*> mChamps;

protected:

    /**
     * @brief creerChampFromType créé un champ de base à partir du type passé en paramètre.
     * Utilisée uniquement dans la méthod créerChamp
     * @param type Le type du champ à créer
     * @return Le champ créé
     */
    Champ* creerChampFromType(const QString& type);

};

#endif // CONTACT_H
