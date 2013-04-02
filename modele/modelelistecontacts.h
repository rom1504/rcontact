/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef MODELELISTECONTACTS_H
#define MODELELISTECONTACTS_H

#include <QAbstractListModel>
#include "contacts.h"

/**
 * @brief La classe ModeleListeContacts est un modèle Qt permettant de gérer l'affichage de la liste des contacts
 */
class ModeleListeContacts : public QAbstractListModel
{
    Q_OBJECT
public:
    /**
     * @brief Le constructeur de la classe
     * @param contact Le contact dont on veut créer le modèle
     * @param parent Le QObject parent
     */
    explicit ModeleListeContacts(Contacts & contacts,QObject *parent=0);

    /**
     * @brief data permet de récupérer une donnée du modèle
     * @param index L'index de la donnée à récupérer
     * @param role Le rôle de la donnée retournée
     * @return Le QVariant conrrespondant à la donnée
     */
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;

    /**
     * @brief rowCount Renvoie le nombre de valeurs dans le contact
     * @return Le nombre de valeurs dans le contact
     */
    int rowCount (const QModelIndex & = QModelIndex()) const;

    /**
     * @brief removeRows Permet de supprimer des lignes
     * @param row L'index de la première ligne à supprimer
     * @param count Le nombre de lignes à supprimer
     * @param parent
     * @return true si les lignes ont été effectivement supprimées, false sinon
     */
    bool removeRows (int row, int count, const QModelIndex & parent = QModelIndex());

    /**
     * @brief ajouterContact ajoute un contact vide dans la liste
     * @return Un pointeur vers le contact ajouté
     */
    Contact * ajouterContact();

    /**
     * @brief ajouterPersonne ajoute un contact de type Personne dans la liste
     * @return Un pointeur vers la personne ajoutée
     */
    Personne * ajouterPersonne();

    /**
     * @brief ajouterOrganisme ajoute un contact de type Organisme dans la liste
     * @return Un pointeur vers l'organisme ajouté
     */
    Organisme * ajouterOrganisme();

    /**
     * @brief charger charge la liste de contact depuis un fichier
     * @param nomFichier Le nom du fichier à charger
     * @param type vCard ou XML
     */
    void charger(QString nomFichier, QString type);

    /**
     * @brief changerTri change la manière de trier
     * @param comp Le nouveau foncteur de comparaison pour le tri
     */
    void changerTri(Comp *comp);


private slots:
    /**
     * @brief trier est le slot qui trie la liste
     */
    void trier();

private:
    /**
    * @brief mContacts est le Contacts dont ce modèle est le modèle
    */
    Contacts & mContacts;

};

#endif // LISTECONTACTS_H
