/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef STRUCTUREEDIT_H
#define STRUCTUREEDIT_H

#include <QWidget>
#include "../modele/structure.h"
#include <QModelIndex>

namespace Ui {
class StructureEdit;
}

/**
 * @brief La classe StructureEdit est un widget permettant d'éditer une structure
 */
class StructureEdit : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(Structure* structure READ structure WRITE setStructure USER true)
    
public:
    /**
     * @brief Constructeur par défaut
     */
    explicit StructureEdit(QWidget *parent = 0);
    /**
     * @brief structure renvoie la Structure associé au widget
     * @return La structure associé au widget
     */
    Structure * structure() const;
    /**
     * @brief setStructure est un setter pour la Structure associée au widget
     * @param s La nouvelle Structure
     */
    void setStructure(Structure *s);
    ~StructureEdit();
    /**
     * @brief sizeHint taille du widget
     * @return Un QSize contenant la taille du widget
     */
    QSize sizeHint() const;

private slots:
    /**
     * @brief redimensionner ajuste automatiquement la taille d'une ligne de la structure (pour l'adapter à l'édition)
     * @param index L'index de la ligne à redimensionner
     */
    void redimensionner(QModelIndex index);
    
private:
    /**
     * @brief ui est la user interface
     */
    Ui::StructureEdit *ui;
    /**
     * @brief mStructure est la Structure représentée par ce widget
     */
    Structure * mStructure;
};

int max(int a,int b);

#endif // STRUCTUREEDIT_H
