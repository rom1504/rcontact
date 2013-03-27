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
#include <QFileDialog>
#include "criterestri.h"
#include "rechercher.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),mModelListeContacts(NULL)
{
    showMaximized();
    QItemEditorFactory *factory = new QItemEditorFactory();
    factory->registerEditor(QVariant::DateTime, new QStandardItemEditorCreator<QDateTimeEdit>());
    factory->registerEditor(QVariant::String, new QStandardItemEditorCreator<QLineEdit>());
    factory->registerEditor((QVariant::Type)qMetaTypeId<Loc*>(), new QStandardItemEditorCreator<LocEdit>());
    factory->registerEditor((QVariant::Type)qMetaTypeId<Enum*>(), new QStandardItemEditorCreator<EnumEdit>());
    factory->registerEditor((QVariant::Type)qMetaTypeId<Structure*>(), new QStandardItemEditorCreator<StructureEdit>());
    QItemEditorFactory::setDefaultFactory(factory);


    ui->setupUi(this);

    connect(ui->listeContacts,SIGNAL(contactActive(int)),this,SIGNAL(contactActive(int)));
    connect(ui->listeContacts,SIGNAL(contactEdite(int)),this,SIGNAL(contactEdite(int)));
    connect(ui->actionSupprimer,SIGNAL(triggered()),ui->listeContacts,SLOT(supprimerContactCourant()));
    connect(ui->actionNouveau_contact,SIGNAL(triggered()),ui->listeContacts,SLOT(creerContact()));
    ui->afficherContact->hide();
    ui->editerContact->hide();
    ui->horizontalLayout->setStretch(1,1);
    ui->horizontalLayout->setStretch(2,1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setModeleListeContacts (ModeleListeContacts *model )
{
    mModelListeContacts=model;
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

void MainWindow::on_actionCharger_triggered()
{
    QString nomFichier;
    if((nomFichier = QFileDialog::getOpenFileName(this, tr("Ouvrir fichier"),"",tr("vCard (*.vcf)")))!="")
    {
        ui->afficherContact->hide();
        ui->editerContact->hide();
        mModelListeContacts->charger(nomFichier);
    }
}

void MainWindow::on_actionTrier_triggered()
{
    Comp * comp=CriteresTri::get();
    if(comp!=NULL) mModelListeContacts->changerTri(comp);
}

void MainWindow::on_actionRechercher_triggered()
{
    Search * search=Rechercher::get();
    if(search!=NULL) emit rechercherContacts(search);
}

void MainWindow::on_actionFinir_la_recherche_triggered()
{
    emit finirLaRecherche();
}
