#ifndef EDITERCONTACT_H
#define EDITERCONTACT_H

#include <QWidget>

namespace Ui {
class EditerContact;
}

class EditerContact : public QWidget
{
    Q_OBJECT
    
public:
    explicit EditerContact(QWidget *parent = 0);
    ~EditerContact();
    
private:
    Ui::EditerContact *ui;
};

#endif // EDITERCONTACT_H
