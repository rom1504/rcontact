#include "structureoutexteedit.h"
#include "ui_structureoutexteedit.h"

StructureOuTexteEdit::StructureOuTexteEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StructureOuTexteEdit)
{
    setAutoFillBackground(true);
    ui->setupUi(this);
    ui->structureEdit->hide();
}

StructureOuTexteEdit::~StructureOuTexteEdit()
{
    delete ui;
}

void StructureOuTexteEdit::on_pushButtonBasculer_clicked()
{
    if(ui->lineEdit->isHidden())
    {
        ui->lineEdit->setText(mStructureOuTexte->toString());
        ui->structureEdit->hide();
        ui->lineEdit->show();
    }
    else
    {
        mStructureOuTexte->fromString(ui->lineEdit->text());
        ui->structureEdit->show();
        ui->lineEdit->hide();
    }
}

QSize max (QSize a,QSize b)
{
    return QSize(max(a.width(),b.width()),max(a.height(),b.height()));
}

QSize StructureOuTexteEdit::sizeHint() const
{
    QSize s=max(ui->structureEdit->sizeHint(),ui->lineEdit->sizeHint());
    return QSize(s.width()+ui->pushButtonBasculer->sizeHint().width()+20,s.height()+10);
}


StructureOuTexte * StructureOuTexteEdit::structureOuTexte() const
{
    if(!(ui->lineEdit->isHidden())) mStructureOuTexte->fromString(ui->lineEdit->text());
    return mStructureOuTexte;
}

void StructureOuTexteEdit::setStructureOuTexte(StructureOuTexte *s)
{
    mStructureOuTexte=s;
    ui->structureEdit->setStructure(s);
    ui->lineEdit->setText(s->toString());
}
