#ifndef RECHERCHER_H
#define RECHERCHER_H

#include <QDialog>
#include "../modele/search.h"

namespace Ui {
class Rechercher;
}

class Rechercher : public QDialog
{
    Q_OBJECT
    
public:
    explicit Rechercher(QWidget *parent = 0);
    ~Rechercher();
    
    static Search * get();


private:
    Ui::Rechercher *ui;
};

#endif // RECHERCHER_H
