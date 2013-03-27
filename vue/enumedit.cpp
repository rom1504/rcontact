#include "enumedit.h"

EnumEdit::EnumEdit(QWidget *parent) :
    QComboBox(parent)
{
}


Enum *EnumEdit::getEnum() const
{
    return new Enum(mEnum,currentIndex());
}

void EnumEdit::setEnum(Enum * c)
{
    addItems(c->valeursPossibles());
    mEnum=c->getEnum();
    setCurrentIndex(c->valeur());
}
