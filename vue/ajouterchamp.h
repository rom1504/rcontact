/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef AJOUTERCHAMP_H
#define AJOUTERCHAMP_H

#include <QDialog>
#include <QPair>

namespace Ui {
class AjouterChamp;
}

/**
 * @brief La classe AjouterChamp est la boîte de dialogue qui s'ouvre quand l'utilisateur clique sur le bouton "Ajouter un champ"
 */
class AjouterChamp : public QDialog
{
    Q_OBJECT
    
public:
    /**
     * @brief get ouvre la boîte de dialogue, attend que l'utilisateur confirme et renvoie les données qui en résulte
     * @return Les données entrée par l'utilisateur dans la boîte de dialogue
     */
    static QPair<QString, QString> get(QString nomClasse);

    
private:
    /**
     * @brief Le constructeur par défaut
     */
    explicit AjouterChamp(QString nomClasse, QWidget *parent = 0);
    virtual ~AjouterChamp();

    /**
     * @brief ui Un pointeur vers la user interface
     */
    Ui::AjouterChamp *ui;
};

#endif // AJOUTERCHAMP_H
