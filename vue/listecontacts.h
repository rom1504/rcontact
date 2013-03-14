#ifndef LISTECONTACTS_H
#define LISTECONTACTS_H

#include <QWidget>
#include <QAbstractItemModel>

namespace Ui {
class ListeContacts;
}

class ListeContacts : public QWidget
{
    Q_OBJECT
    
public:
    explicit ListeContacts(QWidget *parent = 0);
    ~ListeContacts();
    void setModel ( QAbstractItemModel * model );

    
private:
    Ui::ListeContacts *ui;
};

#endif // LISTECONTACTS_H
