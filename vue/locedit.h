#ifndef LOCEDIT_H
#define LOCEDIT_H

#include <QWidget>
#include "../modele/loc.h"

namespace Ui {
class LocEdit;
}

class LocEdit : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(Loc* loc READ loc WRITE setLoc USER true)
    
public:
    explicit LocEdit(QWidget *parent = 0);
    Loc * loc() const;
    void setLoc(Loc *l);

    ~LocEdit();
    
private:
    Ui::LocEdit *ui;
};

#endif // LOCEDIT_H
