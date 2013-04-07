/**
  * @author Romain BEAUMOUNT
  */

#ifndef IMAGEEDIT_H
#define IMAGEEDIT_H

#include <QWidget>
#include "../modele/image.h"

namespace Ui {
class ImageEdit;
}


/**
 * @brief La classe ImageEdit permet d'éditer un champ Image
 */
class ImageEdit : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(Image* image READ image WRITE setImage USER true)
    
public:
    /**
     * @brief Constructeur par défaut
     */
    explicit ImageEdit(QWidget *parent = 0);

    /**
     * @brief image renvoie l'objet Image associé
     * @return L'objet Image associé
     */
    Image * image() const;
    /**
     * @brief setImage modifie l'objet Image
     * @param l'objet Image
     */
    void setImage(Image *i);

    QSize sizeHint() const;

    ~ImageEdit();
    
private slots:
    void on_pushButtonParcourir_clicked();

private:
    Ui::ImageEdit *ui;
};

#endif // IMAGEEDIT_H
