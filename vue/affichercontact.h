#ifndef AFFICHERCONTACT_H
#define AFFICHERCONTACT_H

#include <QWidget>

namespace Ui {
class AfficherContact;
}

class AfficherContact : public QWidget
{
    Q_OBJECT
    
public:
    explicit AfficherContact(QWidget *parent = 0);
    ~AfficherContact();
    
private:
    Ui::AfficherContact *ui;
};

#endif // AFFICHERCONTACT_H
