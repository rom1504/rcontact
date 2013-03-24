#ifndef EDITERCONTACT_H
#define EDITERCONTACT_H

#include <QWidget>
#include <QAbstractItemModel>

namespace Ui {
class EditerContact;
}

class EditerContact : public QWidget
{
    Q_OBJECT
    
public:
    explicit EditerContact(QWidget *parent = 0);
    ~EditerContact();
    void setModel ( QAbstractItemModel * model );

private slots:
    void redimensionner(QModelIndex index);
    void supprimerChampCourant();
    void ajouterChamp();

signals:
    
private:
    Ui::EditerContact *ui;

};

#endif // EDITERCONTACT_H
