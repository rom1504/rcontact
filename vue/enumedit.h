#ifndef ENUMEDIT_H
#define ENUMEDIT_H

#include <QComboBox>
#include "../modele/enum.h"

class EnumEdit : public QComboBox
{
    Q_OBJECT
public:
    explicit EnumEdit(QWidget *parent = 0);
    Q_PROPERTY(Enum enum READ getEnum WRITE setEnum USER true)

    Enum getEnum() const;
    void setEnum(Enum c);

    
public slots:

private:
    int mEnum;


    
};

#endif // ENUMEDIT_H
