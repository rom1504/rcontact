/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef MODELEAFFICHERSTRUCTURE_H
#define MODELEAFFICHERSTRUCTURE_H

#include <QAbstractTableModel>
#include "structure.h"

/**
 * @brief La classe ModeleAfficherStructure est un modèle Qt permettant de gérer l'affichage et l'édition des structure (qui contiennent plusieurs champs)
 */
class ModeleAfficherStructure : public QAbstractTableModel
{
    Q_OBJECT
public:
    /**
     * @brief Le constructeur de la classe
     * @param contact Le contact dont on veut créer le modèle
     * @param parent Le QObject parent
     */
    explicit ModeleAfficherStructure(Structure * structure,QObject *parent = 0);

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
    bool setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole ) ;

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
     * @brief Utilisée seulement en debug ((ou éventuellement dans une version ultérieure)
     */
    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;

signals:

public slots:

private:
    /**
    * @brief mStructure est la structure dont ce modèle est le modèle
    */
   Structure * mStructure;
    
};

#endif // MODELEAFFICHERSTRUCTURE_H
