#ifndef AJOUTERCHAMP_H
#define AJOUTERCHAMP_H

#include <QDialog>
#include <QPair>

namespace Ui {
class AjouterChamp;
}

class AjouterChamp : public QDialog
{
    Q_OBJECT
    
public:
    static QPair<QString, QString> get();

    
private:
    explicit AjouterChamp(QWidget *parent = 0);
    ~AjouterChamp();

    Ui::AjouterChamp *ui;
};

#endif // AJOUTERCHAMP_H
