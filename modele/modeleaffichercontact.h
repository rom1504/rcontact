/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef MODELEAFFICHERCONTACT_H
#define MODELEAFFICHERCONTACT_H

#include <QAbstractTableModel>
#include "contact.h"

/**
 * @brief La classe ModeleAfficherContact est un modèle Qt permettant de gérer l'affichage et l'édition d'un conact
 */
class ModeleAfficherContact : public QAbstractTableModel
{
    Q_OBJECT
public:
    /**
     * @brief Le constructeur de la classe
     * @param contact Le contact dont on veut créer le modèle
     * @param parent Le QObject parent
     */
    explicit ModeleAfficherContact(Contact * contact,QObject *parent = 0);

    /**
     * @brief data permet de récupérer une donnée du modèle
     * @param index L'index de la donnée à récupérer
     * @param role Le rôle de la donnée retournée
     * @return Le QVariant conrrespondant à la donnée
     */
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;

    /**
     * @brief setData modifie une donnée du modèle
     * @param index L'index de la donée à modifier
     * @param value La nouvelle valeur
     * @param role Le rôle de la donnée
     * @return true si il y a eu modification, false sinon
     */
    bool setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole ) ; // utilisé pour l'édition (changer le nom de ce fichier/classe ?)

    /**
     * @brief rowCount Renvoie le nombre de valeurs dans le contact
     * @return Le nombre de valeurs dans le contact
     */
    int rowCount ( const QModelIndex & = QModelIndex() ) const;

    /**
     * @return 2
     */
    int columnCount (const QModelIndex & = QModelIndex()) const;

    /**
     * @brief flags Renvoie les flags caractéristiques d'une donnée du modèle
     * @param index L'index de la donnée
     * @return Les flags de la donnée
     */
    Qt::ItemFlags flags ( const QModelIndex & index ) const;

    /**
     * @brief removeRows Permet de supprimer des lignes
     * @param row L'index de la première ligne à supprimer
     * @param count Le nombre de lignes à supprimer
     * @param parent
     * @return true si les lignes ont été effectivement supprimées, false sinon
     */
    bool removeRows (int row, int count, const QModelIndex & parent = QModelIndex());

    /**
     * @brief rendreEditable Permet de rendre le modèle éditable
     */
    void rendreEditable();

    /**
     * @brief Utilisée seulement en debug (ou éventuellement dans une version ultérieure)
     */
    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;

    /**
     * @brief insertRows permet d'insérer des lignes
     * @param row L'index où on veut insérer les lignes
     * @param count Le nombre de lignes à insérer
     * @param parent L'objeet parent
     * @return true si les lignes ont effectivement été insérées
     */
    bool insertRows ( int row, int count, const QModelIndex & parent  );
    
signals:

private slots:
    /**
     * @brief maj est le slot appelé lorsqu'on met à jour le modèle
     */
    void maj();

private:
    /**
    * @brief mContact est le contact dont ce modèle est le modèle
    */
   Contact * mContact;
   /**
    * @brief mEditable est à true si le modèle est éditable
    */
   bool mEditable;

    
};

#endif // MODELEAFFICHERCONTACT_H
