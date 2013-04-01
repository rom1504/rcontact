#include "ajouterchamp.h"
#include "ui_ajouterchamp.h"

AjouterChamp::AjouterChamp(QString nomClasse,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterChamp)
{
    ui->setupUi(this);
    QStringList liste;

    liste<<tr("nom")<<tr("tel")<<tr("adresse")<<tr("email")<<tr("site")<<tr("type")<<tr("date")<<tr("note");
    if(nomClasse=="Personne") liste<<tr("sexe")<<tr("photo")<<tr("organisation");
    else if(nomClasse=="Organisme") liste<<tr("logo")<<tr("membre");

    ui->comboBoxType->addItems(liste);
    ui->lineEditNom->setText(tr("nom"));
    connect(ui->comboBoxType,SIGNAL(currentIndexChanged(QString)),ui->lineEditNom,SLOT(setText(QString)));
}

AjouterChamp::~AjouterChamp()
{
    delete ui;
}

QPair<QString, QString> AjouterChamp::get(QString nomClasse)
{
    QString nom="";
    QString type="";
    AjouterChamp* ajouterChamp=new AjouterChamp(nomClasse);
    if(ajouterChamp->exec() == QDialog::Accepted)
    {
        nom=ajouterChamp->ui->lineEditNom->text();
        type=ajouterChamp->ui->comboBoxType->currentText();
    }
    return qMakePair(nom,type);
}
