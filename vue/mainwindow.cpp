#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->listeContacts,SIGNAL(contactActive(int)),this,SIGNAL(contactActive(int)));
    connect(ui->listeContacts,SIGNAL(contactEdite(int)),this,SIGNAL(contactEdite(int)));
    connect(ui->actionSupprimer,SIGNAL(triggered()),ui->listeContacts,SLOT(supprimerContactCourant()));
    connect(ui->actionNouveau_contact,SIGNAL(triggered()),ui->listeContacts,SLOT(creerContact()));
    ui->afficherContact->hide();
    ui->editerContact->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setModeleListeContacts ( QAbstractItemModel * model )
{
    ui->listeContacts->setModel(model);
}


void MainWindow::setModeleAfficherContact ( QAbstractItemModel * model )
{
    ui->editerContact->hide();
    ui->afficherContact->show();
    ui->afficherContact->setModel(model);
}

void MainWindow::setModeleEditerContact ( QAbstractItemModel * model )
{
    ui->editerContact->show();
    ui->afficherContact->hide();
    ui->editerContact->setModel(model);
}
