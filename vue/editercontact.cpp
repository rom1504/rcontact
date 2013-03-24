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
        connect(ui->tableViewChamps->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(redimensionner(QModelIndex)));
        ui->tableViewChamps->resizeColumnsToContents();
        ui->tableViewChamps->resizeRowsToContents();
        connect(ui->tableViewChamps->model(),SIGNAL(dataChanged(QModelIndex,QModelIndex)),ui->tableViewChamps,SLOT(resizeColumnsToContents()));
        connect(ui->tableViewChamps->model(),SIGNAL(dataChanged(QModelIndex,QModelIndex)),ui->tableViewChamps,SLOT(resizeRowsToContents()));
    }
}

void EditerContact::supprimerChampCourant()
{
    ui->tableViewChamps->model()->removeRow(ui->tableViewChamps->currentIndex().row());
}

int max(int a,int b)
{
    return a>b ? a : b;
}

void EditerContact::redimensionner(QModelIndex index)
{
    ui->tableViewChamps->verticalHeader()->resizeSection(index.row(),max(ui->tableViewChamps->verticalHeader()->sectionSize(index.row()),ui->tableViewChamps->indexWidget(index)->sizeHint().height()));
    ui->tableViewChamps->horizontalHeader()->resizeSection(index.column(),max(ui->tableViewChamps->horizontalHeader()->sectionSize(index.column()),ui->tableViewChamps->indexWidget(index)->sizeHint().width()));
}
