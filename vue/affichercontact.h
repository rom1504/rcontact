#ifndef AFFICHERCONTACT_H
#define AFFICHERCONTACT_H

#include <QWidget>
#include <QAbstractItemModel>

namespace Ui {
class AfficherContact;
}

class AfficherContact : public QWidget
{
    Q_OBJECT
    
public:
    explicit AfficherContact(QWidget *parent = 0);
    ~AfficherContact();
    void setModel ( QAbstractItemModel * model );
    
private:
    Ui::AfficherContact *ui;
};

#endif // AFFICHERCONTACT_H
