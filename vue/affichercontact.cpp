#include "affichercontact.h"
#include "ui_affichercontact.h"

AfficherContact::AfficherContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AfficherContact)
{
    ui->setupUi(this);
    ui->tableViewChamps->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    ui->tableViewChamps->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
}

AfficherContact::~AfficherContact()
{
    delete ui;
}

void AfficherContact::setModel ( QAbstractItemModel * model )
{
    ui->tableViewChamps->setModel(model);
}
