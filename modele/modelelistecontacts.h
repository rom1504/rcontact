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
     * @brief insertRows permet d'insérer des lignes
     * @param row L'index où on veut insérer les lignes
     * @param count Le nombre de lignes à insérer
     * @param parent L'objeet parent
     * @return true si les lignes ont effectivement été insérées
     */
    bool insertRows (int row, int count, const QModelIndex &parent) ;
    void charger(QString nomFichier);
    void changerTri(Comp *comp);


private slots:
    void trier();

private:
    /**
    * @brief mContacts est le Contacts dont ce modèle est le modèle
    */
    Contacts & mContacts;

};

#endif // LISTECONTACTS_H
