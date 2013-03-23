#include "editercontact.h"
#include "ui_editercontact.h"

EditerContact::EditerContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditerContact)
{
    ui->setupUi(this);
    connect(ui->pushButtonSupprimerChamp,SIGNAL(pressed()),this,SLOT(supprimerChampCourant()));
}

EditerContact::~EditerContact()
{
    delete ui;
}

void EditerContact::setModel ( QAbstractItemModel * model )
{
    ui->tableViewChamps->setModel(model);
    if(model!=NULL)
    {
        ui->tableViewChamps->resizeColumnsToContents();
        connect(model,SIGNAL(dataChanged(QModelIndex,QModelIndex)),ui->tableViewChamps,SLOT(resizeColumnsToContents()));
    }
}

void EditerContact::supprimerChampCourant()
{
    ui->tableViewChamps->model()->removeRow(ui->tableViewChamps->currentIndex().row());
}
