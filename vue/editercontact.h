/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef EDITERCONTACT_H
#define EDITERCONTACT_H

#include <QWidget>
#include <QAbstractItemModel>

namespace Ui {
class EditerContact;
}

/**
 * @brief La classe EditerContact est la zone d'édition d'un contact
 */
class EditerContact : public QWidget
{
    Q_OBJECT
    
public:
    /**
     * @brief Constructeur par défaut
     */
    explicit EditerContact(QWidget *parent = 0);
    ~EditerContact();

    /**
     * @brief setModel détermine le modèle à aficher
     * @param model Le modèle à afficher
     */
    void setModel ( QAbstractItemModel * model );

private slots:
    /**
     * @brief redimensionner met à jour la taille de la colonne
     * @param index L'index de la colonne à redimensionner
     */
    void redimensionner(QModelIndex index);

    /**
     * @brief supprimerChampCourant supprime le champ en subrillance
     */
    void supprimerChampCourant();

    /**
     * @brief ajouterChamp ajoute un champ au contact
     */
    void ajouterChamp();

signals:
    
private:
    /**
     * @brief ui Un pointeur vers la user interface
     */
    Ui::EditerContact *ui;

};

#endif // EDITERCONTACT_H
