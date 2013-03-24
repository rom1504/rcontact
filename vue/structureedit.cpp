#include "structureedit.h"
#include "ui_structureedit.h"
#include "../modele/modeleafficherstructure.h"

StructureEdit::StructureEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StructureEdit)
{
    setAutoFillBackground(true);
    ui->setupUi(this);
}

StructureEdit::~StructureEdit()
{
    delete ui;
}

Structure StructureEdit::structure() const
{
    return mStructure;
}

void StructureEdit::setStructure(Structure s)
{
    mStructure=s;
    ui->tableViewChamps->setModel(new ModeleAfficherStructure(&mStructure));
    connect(ui->tableViewChamps->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(redimensionner(QModelIndex)));
    ui->tableViewChamps->resizeColumnsToContents();
    ui->tableViewChamps->resizeRowsToContents();
    connect(ui->tableViewChamps->model(),SIGNAL(dataChanged(QModelIndex,QModelIndex)),ui->tableViewChamps,SLOT(resizeColumnsToContents()));
    connect(ui->tableViewChamps->model(),SIGNAL(dataChanged(QModelIndex,QModelIndex)),ui->tableViewChamps,SLOT(resizeRowsToContents()));
}

QSize StructureEdit::sizeHint() const
{
    QSize s=ui->tableViewChamps->sizeHint();
    return QSize(s.width()*2,ui->tableViewChamps->model()->rowCount()*30);
}

void StructureEdit::redimensionner(QModelIndex index)
{
    if(index.column()!=0)
    {
        ui->tableViewChamps->verticalHeader()->resizeSection(index.row(),max(ui->tableViewChamps->verticalHeader()->sectionSize(index.row()),ui->tableViewChamps->indexWidget(index)->sizeHint().height()));
        ui->tableViewChamps->horizontalHeader()->resizeSection(index.column(),max(ui->tableViewChamps->horizontalHeader()->sectionSize(index.column()),ui->tableViewChamps->indexWidget(index)->sizeHint().width()));
    }
}
