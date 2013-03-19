#include "affichercontact.h"
#include "ui_affichercontact.h"

AfficherContact::AfficherContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AfficherContact)
{
    ui->setupUi(this);
    ui->tableViewChamps->verticalHeader ()->hide();
}

AfficherContact::~AfficherContact()
{
    delete ui;
}

void AfficherContact::setModel ( QAbstractItemModel * model )
{
    ui->tableViewChamps->setModel(model);
    if(model!=NULL)
    {
        ui->tableViewChamps->resizeColumnsToContents();
        connect(model,SIGNAL(dataChanged(QModelIndex,QModelIndex)),ui->tableViewChamps,SLOT(resizeColumnsToContents()));
    }
}
