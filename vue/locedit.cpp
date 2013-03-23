#include "locedit.h"
#include "ui_locedit.h"

LocEdit::LocEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LocEdit)
{
    setAutoFillBackground(true);
    ui->setupUi(this);
}

LocEdit::~LocEdit()
{
    delete ui;
}

Loc LocEdit::loc() const
{
    return Loc(ui->doubleSpinBoxLatitude->value(),ui->doubleSpinBoxLongitude->value());
}

void LocEdit::setLoc(Loc l)
{
    ui->doubleSpinBoxLatitude->setValue(l.latitude());
    ui->doubleSpinBoxLongitude->setValue(l.longitude());
}
