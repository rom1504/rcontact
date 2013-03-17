#include "listecontacts.h"
#include "ui_listecontacts.h"

ListeContacts::ListeContacts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListeContacts)
{
    ui->setupUi(this);
    connect(ui->listeContacts,SIGNAL(activated(QModelIndex)),this,SIGNAL(contactActive(QModelIndex)));
    connect(ui->pushButtonAfficher,SIGNAL(clicked()),this,SLOT(afficherContactCourant()));
    connect(ui->pushButtonSupprimer,SIGNAL(clicked()),this,SLOT(supprimerContactCourant()));
    connect(ui->pushButtonEditer,SIGNAL(clicked()),this,SLOT(editerContactCourant()));
}

ListeContacts::~ListeContacts()
{
    delete ui;
}


void ListeContacts::setModel ( QAbstractItemModel * model )
{
    ui->listeContacts->setModel(model);
}

void ListeContacts::supprimerContactCourant()
{
    emit contactSupprime(ui->listeContacts->currentIndex());
}

void ListeContacts::afficherContactCourant()
{
    emit contactActive(ui->listeContacts->currentIndex());
}

void ListeContacts::editerContactCourant()
{
    emit contactEdite(ui->listeContacts->currentIndex());
}
