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
#include "structureoutexteedit.h"
#include "../modele/nom.h"
#include <QCalendarWidget>
#include "dateedit.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),mModelListeContacts(NULL)
{
    showMaximized();
    QItemEditorFactory *factory = new QItemEditorFactory();
    factory->registerEditor(QVariant::DateTime, new QStandardItemEditorCreator<DateEdit>());
    factory->registerEditor(QVariant::String, new QStandardItemEditorCreator<QLineEdit>());
    factory->registerEditor((QVariant::Type)qMetaTypeId<Loc*>(), new QStandardItemEditorCreator<LocEdit>());
    factory->registerEditor((QVariant::Type)qMetaTypeId<Enum*>(), new QStandardItemEditorCreator<EnumEdit>());
    factory->registerEditor((QVariant::Type)qMetaTypeId<Structure*>(), new QStandardItemEditorCreator<StructureEdit>());
    factory->registerEditor((QVariant::Type)qMetaTypeId<StructureOuTexte*>(), new QStandardItemEditorCreator<StructureOuTexteEdit>());
    QItemEditorFactory::setDefaultFactory(factory);


    ui->setupUi(this);
    setWindowIcon(/*QIcon::fromTheme("preferences-desktop-personal",*/QIcon(":icones/gestionnaire_contact.png")/*)*/);
    ui->actionNouvelle_personne->setIcon(/*QIcon::fromTheme("contact-new",*/QIcon(":/icones/ajouter.png")/*)*/);
    ui->actionNouveau_organisme->setIcon(QIcon(":/icones/ajouterOrganisme.png"));
    ui->actionCharger->setIcon(/*QIcon::fromTheme("document-open",*/QIcon(":/icones/ouvrir.png")/*)*/);
    ui->actionEnregistrer->setIcon(/*QIcon::fromTheme("document-save-as",*/QIcon(":/icones/enregistrer.png")/*)*/);
    ui->actionRechercher->setIcon(/*QIcon::fromTheme("edit-find",*/QIcon(":/icones/rechercher.png")/*)*/);
    ui->actionSupprimer->setIcon(/*QIcon::fromTheme("edit-delete",*/QIcon(":/icones/supprimer.png")/*)*/);
    ui->actionQuitter->setIcon(/*QIcon::fromTheme("application-exit",*/QIcon(":/icones/quitter.png")/*)*/);
    ui->actionFinir_la_recherche->setIcon(/*QIcon::fromTheme("go-previous",*/QIcon(":/icones/precedent.png")/*)*/);
    ui->actionTrier->setIcon(/*QIcon::fromTheme("view-sort-ascending",*/QIcon(":/icones/trier.png")/*)*/);
    ui->actionNouvelle_liste->setIcon(QIcon(":/icones/nouvelleListe.png"));

    connect(ui->listeContacts,SIGNAL(contactActive(int)),this,SIGNAL(contactActive(int)));
    connect(ui->listeContacts,SIGNAL(contactEdite(int)),this,SIGNAL(contactEdite(int)));
    connect(ui->actionSupprimer,SIGNAL(triggered()),ui->listeContacts,SLOT(supprimerContactCourant()));
    connect(ui->actionNouvelle_personne,SIGNAL(triggered()),ui->listeContacts,SLOT(creerPersonne()));
    connect(ui->actionNouveau_organisme,SIGNAL(triggered()),ui->listeContacts,SLOT(creerOrganisme()));
    cacherContact();
    ui->horizontalLayout->setStretch(1,1);
    ui->horizontalLayout->setStretch(2,1);
}

void MainWindow::cacherContact()
{
    ui->afficherContact->hide();
    ui->editerContact->hide();
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
    QString type=tr("vCard(*.vcf)");
    if((nomFichier = QFileDialog::getOpenFileName(this, tr("Ouvrir fichier"),"",tr("vCard(*.vcf);;XML(*.xml)"),&type))!="")
    {
        ui->afficherContact->hide();
        ui->editerContact->hide();
        mModelListeContacts->charger(nomFichier,type.split("(")[0]);
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

void MainWindow::on_actionEnregistrer_triggered()
{
    QString nomFichier;
    QString type=tr("vCard(*.vcf)");
    if((nomFichier = QFileDialog::getSaveFileName(this, tr("Enregistrer fichier"),"",tr("vCard(*.vcf);;XML(*.xml)"),&type))!="")
    {
        emit enregistrerContacts(nomFichier,type.split("(")[0]);
    }
}

void MainWindow::on_actionNouvelle_liste_triggered()
{
    mModelListeContacts->vider();
   cacherContact();
}
