#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTimeEdit>
#include <QVariant>
#include <QItemEditorFactory>
#include <QItemEditorCreatorBase>
#include <QLineEdit>
#include "locedit.h"
#include "enumedit.h"
#include "structureedit.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QItemEditorFactory *factory = new QItemEditorFactory();
    factory->registerEditor(QVariant::DateTime, new QStandardItemEditorCreator<QDateTimeEdit>());
    factory->registerEditor(QVariant::String, new QStandardItemEditorCreator<QLineEdit>());
    factory->registerEditor((QVariant::Type)qMetaTypeId<Loc>(), new QStandardItemEditorCreator<LocEdit>());
    factory->registerEditor((QVariant::Type)qMetaTypeId<Enum>(), new QStandardItemEditorCreator<EnumEdit>());
    factory->registerEditor((QVariant::Type)qMetaTypeId<Structure>(), new QStandardItemEditorCreator<StructureEdit>());
    QItemEditorFactory::setDefaultFactory(factory);


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
