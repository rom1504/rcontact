#include "listecontacts.h"
#include "ui_listecontacts.h"
#include "../modele/modelelistecontacts.h"

ListeContacts::ListeContacts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListeContacts),mModel(NULL)
{
    ui->setupUi(this);
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


void ListeContacts::setModel ( ModeleListeContacts * model )
{
    mModel=model;
    ui->listeContacts->setModel(model);
    connect(ui->listeContacts->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(afficherContact(QModelIndex)));
}

void ListeContacts::supprimerContactCourant()
{
    ui->listeContacts->model()->removeRow(ui->listeContacts->currentIndex().row());
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
