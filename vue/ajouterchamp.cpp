#include "ajouterchamp.h"
#include "ui_ajouterchamp.h"
#include "../modele/card.h"
#include "../modele/enum.h"
#include "../modele/loc.h"
#include "../modele/structure.h"
#include "../modele/texte.h"
#include "../modele/timestamp.h"
#include "../modele/url.h"

AjouterChamp::AjouterChamp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterChamp)
{
    ui->setupUi(this);
    QStringList list;
    list<<"card"<<"enum"<<"loc"<<"structure"<<"texte"<<"timestamp"<<"url"<<"sexe"<<"tel";
    ui->comboBoxType->addItems(list);
}

AjouterChamp::~AjouterChamp()
{
    delete ui;
}

QPair<QString, Champ *> AjouterChamp::get()
{
    AjouterChamp* ajouterChamp=new AjouterChamp();
    if(ajouterChamp->exec() == QDialog::Accepted)
    {
        QString nom=ajouterChamp->ui->lineEditNom->text();
        QString type=ajouterChamp->ui->comboBoxType->currentText();
        Champ * champ;
        if(type=="card") champ=new Card();
        else if(type=="enum") champ=new Enum();
        else if(type=="loc") champ=new Loc();
        else if(type=="structure") champ=new Structure();
        else if(type=="texte") champ=new Texte();
        else if(type=="timestamp") champ=new Timestamp();
        else if(type=="url") champ=new Url();
        else if(type=="sexe") champ=new Enum("homme");
        else if(type=="tel")
        {
            Structure * structure=new Structure();
            structure->ajouterChamp("type",new Enum("work"));
            structure->ajouterChamp("type tel",new Enum("fixe"));
            structure->ajouterChamp("type données",new Enum("voice"));
            structure->ajouterChamp("n°",new Texte(""));
            champ=structure;

        }
        else return qMakePair(QString(""),(Champ*)NULL);
        return qMakePair(nom,champ);
    }
    return qMakePair(QString(""),(Champ*)NULL);
}
