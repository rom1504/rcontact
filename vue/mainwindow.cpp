#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->listeContacts,SIGNAL(contactActive(QModelIndex)),this,SIGNAL(contactActive(QModelIndex)));
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
    ui->afficherContact->setModel(model);
}
