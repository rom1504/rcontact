#include "affichercontact.h"
#include "ui_affichercontact.h"

AfficherContact::AfficherContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AfficherContact)
{
    ui->setupUi(this);
}

AfficherContact::~AfficherContact()
{
    delete ui;
}

void AfficherContact::setModel ( QAbstractItemModel * model )
{
    if(model!=NULL)
    {
        ui->tableViewChamps->setModel(model);
        ui->tableViewChamps->resizeColumnsToContents();
        connect(model,SIGNAL(dataChanged(QModelIndex,QModelIndex)),ui->tableViewChamps,SLOT(resizeColumnsToContents()));
    }
}
