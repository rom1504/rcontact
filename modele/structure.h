/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef STRUCTURE_H
#define STRUCTURE_H

#include "champ.h"
#include <QMultiMap>

/**
 * @brief La classe Structure représente un champ structuré (qui contient une liste de champs)
 */
class Structure : public Champ
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur vide
     */
    explicit Structure(QObject * parent=0);

    /**
     * @brief Constructeur de copie
     */
    Structure(const Structure &s, QObject * parent=0);
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


    int supprimerChamp(const int index);

    /**
     * @brief L'opérateur de comparaison
     */
    bool operator==(const Structure & c) const;
    /**
     * @brief toString convertit l'objet en format lisible
     * @return une QString contenant un format lisible du champ
     */
    virtual QString toString() const;
    /**
     * @brief fromString convertit un QString en Structure
     * @param s La QString à convertir
     * @return true si la conversion a réussi, false sinon
     */
    virtual bool fromString(const QString s);


    /**
     * @brief opérateur d'accès
     */
    const QPair<QString,Champ*> operator[](const int n) const;


    /**
     * @brief operator d'accès qui utilise le nom du champ
     * @param s Le nom du champ à accéder
     * @return Un pointeur vers le premier Champ qui porte le nom passé en paramètre.
     */
    const Champ* operator[](const QString s) const;


    virtual QVariant toVariant();
    virtual bool fromVariant(const QVariant v);

    /**
     * @brief nombreValeurs
     * @return le nombre de valeur totales
     */
    int nombreValeurs() const;

    void remplacer(QString s,Champ * c);

    QVariant image();


    QString avoirChamp(QString nom) const;

    void essayerEncore();

    QString toXML() const;


protected:
    void vider();


protected:
    /**
     * @brief mChamps contient la liste des champs contenu dans la structure
     */
    QMultiMap<QString,Champ*> mChamps;
};

Q_DECLARE_METATYPE (Structure*)

#endif // STRUCTURE_H
