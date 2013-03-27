#include "criterestri.h"
#include "ui_criterestri.h"

CriteresTri::CriteresTri(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CriteresTri)
{
    ui->setupUi(this);
}

CriteresTri::~CriteresTri()
{
    delete ui;
}


Comp * CriteresTri::get()
{
    CriteresTri* criteresTri=new CriteresTri();
    if(criteresTri->exec() == QDialog::Accepted)
        return new Comp(criteresTri->ui->radioButtonAscendant->isChecked(),criteresTri->ui->comboBoxCritereTri->currentText());
    return NULL;
}
