/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef STRUCTUREOUTEXTEEDIT_H
#define STRUCTUREOUTEXTEEDIT_H

#include <QWidget>
#include "../modele/structureoutexte.h"
#include "../modele/nom.h"

namespace Ui {
class StructureOuTexteEdit;
}

/**
 * @brief La classe StructureOuTexteEdit est un widget permettant d'éditer un chmp StructureOuTexte
 */
class StructureOuTexteEdit : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(StructureOuTexte* structureOuTexte READ structureOuTexte WRITE setStructureOuTexte USER true)
    
public:
    /**
     * @brief Constructeur par défaut
     */
    explicit StructureOuTexteEdit(QWidget *parent = 0);
    /**
     * @brief structureOuTexte renvoie le StructureOuTexte représenté par l'objet
     * @return Le StructureOuTexte représenté par l'objet
     */
    StructureOuTexte * structureOuTexte() const;
    /**
     * @brief setStructureOuTexte est le setter du StructureOuTexte associé
     * @param s Le nouveau StructureOuTexte
     */
    void setStructureOuTexte(StructureOuTexte *s);
    ~StructureOuTexteEdit();
    /**
     * @brief sizeHint renvoie la taille du widget
     * @return La taille du widget
     */
    QSize sizeHint() const;
    
private slots:
    /**
     * @brief on_pushButtonBasculer_clicked est le slot appelé lors du clic
     */
    void on_pushButtonBasculer_clicked();

private:
    /**
     * @brief ui est la user interface
     */
    Ui::StructureOuTexteEdit *ui;
    /**
     * @brief mStructureOuTexte est le StructureOuTextAssocié
     */
    StructureOuTexte * mStructureOuTexte;
};

#endif // STRUCTUREOUTEXTEEDIT_H
