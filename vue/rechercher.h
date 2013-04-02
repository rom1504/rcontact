/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef RECHERCHER_H
#define RECHERCHER_H

#include <QDialog>
#include "../modele/search.h"

namespace Ui {
class Rechercher;
}

/**
 * @brief La classe Rechercher est la popup qui permet d'entrer les options de recherche
 */
class Rechercher : public QDialog
{
    Q_OBJECT
    
public:
    /**
     * @brief Constructeur par défaut
     */
    explicit Rechercher(QWidget *parent = 0);
    ~Rechercher();
    
    /**
     * @brief get renvoie le foncteur pour la recherche
     * @return Le foncteur pour la recherche
     */
    static Search * get();


private:
    /**
     * @brief ui est la user interface
     */
    Ui::Rechercher *ui;
};

#endif // RECHERCHER_H
