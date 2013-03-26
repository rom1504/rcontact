#include "ajouterchamp.h"
#include "ui_ajouterchamp.h"

AjouterChamp::AjouterChamp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterChamp)
{
    ui->setupUi(this);
    QStringList list;
//    list<<"card"<<"enum"<<"loc"<<"structure"<<"texte"<<"timestamp"<<"url";
    list<<"nom"<<"sexe"<<"tel"<<"adresse"<<"email"<<"site"<<"photo"<<"organisation"<<"type"<<"date MAJ"<<"note";
    //olist<<"nom"<<"tel"<<"adresse"<<"email"<<"site"<<"logo"<<"organisation"<<"date MAJ"<<"note";
    ui->comboBoxType->addItems(list);
    ui->lineEditNom->setText("nom");
    connect(ui->comboBoxType,SIGNAL(currentIndexChanged(QString)),ui->lineEditNom,SLOT(setText(QString)));
}

AjouterChamp::~AjouterChamp()
{
    delete ui;
}

QPair<QString, QString> AjouterChamp::get()
{
    QString nom="";
    QString type="";
    AjouterChamp* ajouterChamp=new AjouterChamp();
    if(ajouterChamp->exec() == QDialog::Accepted)
    {
        nom=ajouterChamp->ui->lineEditNom->text();
        type=ajouterChamp->ui->comboBoxType->currentText();
    }
    return qMakePair(nom,type);
}
