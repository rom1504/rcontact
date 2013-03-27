#ifndef CRITERESTRI_H
#define CRITERESTRI_H

#include <QDialog>
#include <QPair>

namespace Ui {
class CriteresTri;
}

class CriteresTri : public QDialog
{
    Q_OBJECT
    
public:
    explicit CriteresTri(QWidget *parent = 0);
    ~CriteresTri();

    static QPair<bool,QString> get();
    
private:
    Ui::CriteresTri *ui;
};

#endif // CRITERESTRI_H
