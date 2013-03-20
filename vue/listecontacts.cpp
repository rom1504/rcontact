#include "listecontacts.h"
#include "ui_listecontacts.h"

ListeContacts::ListeContacts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListeContacts)
{
    ui->setupUi(this);
    connect(ui->listeContacts,SIGNAL(activated(QModelIndex)),this,SLOT(afficherContact(QModelIndex)));
    connect(ui->pushButtonAfficher,SIGNAL(clicked()),this,SLOT(afficherContactCourant()));
    connect(ui->pushButtonSupprimer,SIGNAL(clicked()),this,SLOT(supprimerContactCourant()));
    connect(ui->pushButtonEditer,SIGNAL(clicked()),this,SLOT(editerContactCourant()));
}

ListeContacts::~ListeContacts()
{
    delete ui;
}

int ListeContacts::indexContactCourant()
{
    return ui->listeContacts->currentIndex().row();
}


void ListeContacts::setModel ( QAbstractItemModel * model )
{
    ui->listeContacts->setModel(model);
}

void ListeContacts::supprimerContactCourant()
{
    ui->listeContacts->model()->removeRow(ui->listeContacts->currentIndex().row());
    emit contactActive(-1);
}

void ListeContacts::afficherContactCourant()
{
    afficherContact(ui->listeContacts->currentIndex());
}

void ListeContacts::editerContactCourant()
{
    emit contactEdite(ui->listeContacts->currentIndex().row());
}

void ListeContacts::afficherContact(const QModelIndex & index)
{
    emit contactActive(index.row());
}

void ListeContacts::creerContact()
{
    ui->listeContacts->model()->insertRow(ui->listeContacts->model()->rowCount());
    emit contactEdite(ui->listeContacts->model()->rowCount()-1);
}
