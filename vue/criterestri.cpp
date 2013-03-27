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


QPair<bool,QString> CriteresTri::get()
{
    bool ordre=true;
    QString critereTri="";
    CriteresTri* criteresTri=new CriteresTri();
    if(criteresTri->exec() == QDialog::Accepted)
    {
        ordre=criteresTri->ui->radioButtonAscendant->isChecked();
        critereTri=criteresTri->ui->comboBoxCritereTri->currentText();
    }
    return qMakePair(ordre,critereTri);
}
