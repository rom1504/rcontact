/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef LOCEDIT_H
#define LOCEDIT_H

#include <QWidget>
#include "../modele/loc.h"

namespace Ui {
class LocEdit;
}

/**
 * @brief La classe LocEdit est un widget permettant d'éditer une localisation
 */
class LocEdit : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(Loc* loc READ loc WRITE setLoc USER true)
    
public:
    /**
     * @brief Constructeur par défaut
     */
    explicit LocEdit(QWidget *parent = 0);
    /**
     * @brief loc renvoie l'objet Loc associé
     * @return L'objet Loc associé
     */
    Loc * loc() const;
    /**
     * @brief setLoc modifie l'objet Loc
     * @param l'objet Loc
     */
    void setLoc(Loc *l);

    ~LocEdit();
    
private:
    /**
     * @brief ui est la user interface
     */
    Ui::LocEdit *ui;
};

#endif // LOCEDIT_H
