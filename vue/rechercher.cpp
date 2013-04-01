#include "rechercher.h"
#include "ui_rechercher.h"

Rechercher::Rechercher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rechercher)
{
    ui->setupUi(this);
}

Rechercher::~Rechercher()
{
    delete ui;
}

Search * Rechercher::get()
{
    Rechercher* rechercher=new Rechercher();
    if(rechercher->exec() == QDialog::Accepted) return new Search(rechercher->ui->lineEditNom->text(),rechercher->ui->checkBoxCase->isChecked(),
                                                                  rechercher->ui->checkBoxPersonne->isChecked(),rechercher->ui->checkBoxOrganisme->isChecked());
    return NULL;
}
