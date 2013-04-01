#include "listecontacts.h"
#include "ui_listecontacts.h"
#include "../modele/modeleaffichercontact.h"
#include "../modele/modelelistecontacts.h"
#include "editercontact.h"
#include "../modele/personne.h"

ListeContacts::ListeContacts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListeContacts),mModel(NULL)
{
    ui->setupUi(this);
    connect(ui->pushButtonAfficher,SIGNAL(clicked()),this,SLOT(afficherContactCourant()));
    connect(ui->pushButtonSupprimer,SIGNAL(clicked()),this,SLOT(supprimerContactCourant()));
    connect(ui->pushButtonEditer,SIGNAL(clicked()),this,SLOT(editerContactCourant()));
    ui->listeContacts->setResizeMode(QListView::Adjust);
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
    if(ui->listeContacts->selectionModel()->currentIndex().isValid()) ui->listeContacts->model()->removeRow(ui->listeContacts->selectionModel()->currentIndex().row());
}

void ListeContacts::afficherContactCourant()
{
    if(ui->listeContacts->selectionModel()->currentIndex().isValid()) afficherContact(ui->listeContacts->selectionModel()->currentIndex());
}

void ListeContacts::editerContactCourant()
{
    if(ui->listeContacts->selectionModel()->currentIndex().isValid()) emit contactEdite(ui->listeContacts->selectionModel()->currentIndex().row());
}

void ListeContacts::afficherContact(const QModelIndex & index)
{
    emit contactActive(index.row());
}

void ListeContacts::creerPersonne()
{
    creerContact(mModel->ajouterPersonne());
}


void ListeContacts::creerOrganisme()
{
    creerContact(mModel->ajouterOrganisme());
}

void ListeContacts::creerContact(Contact * contact) // rendre modal ?
{
   EditerContact * editerContact=new EditerContact();
   ModeleAfficherContact * modeleAfficherContact=new ModeleAfficherContact(contact);
   modeleAfficherContact->rendreEditable();
   editerContact->move(300,150);
   editerContact->setModel(modeleAfficherContact);
   editerContact->setWindowModality(Qt::ApplicationModal);
   editerContact->show();
}
