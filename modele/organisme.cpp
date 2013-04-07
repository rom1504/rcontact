#include "organisme.h"
#include <QPixmap>
#include "image.h"
#include "membre.h"

Organisme::Organisme(QObject * parent) : Contact(parent)
{
}

QVariant Organisme::image() const
{
    const Champ * champ=at("logo");
    if(champ==NULL) return QVariant();
    QVariant v=champ->image();
    if(!(v.isValid())) return QVariant();
    QPixmap p=champ->image().value<QPixmap>();
    if(p.isNull()) return QVariant();
    p=p.scaledToWidth(60);
    return p;
}

Organisme *Organisme::creerDefaut()
{
    Organisme * nouveau = new Organisme();
    nouveau->creerChamp(tr("nom"),tr("nom"));
//    nouveau->creerChamp(tr("tel"),tr("tel"));
//    nouveau->creerChamp(tr("adresse"),tr("adresse"));
//    nouveau->creerChamp(tr("email"),tr("email"));
//    nouveau->creerChamp(tr("site"),tr("site"));
//    nouveau->creerChamp(tr("logo"),tr("logo"));
//    nouveau->creerChamp(tr("membre"),tr("membre"));
//    nouveau->creerChamp(tr("date MAJ"),tr("date"));
//    nouveau->creerChamp(tr("note"),tr("note"));
    return nouveau;
}

Champ* Organisme::gnom(const QString nom,const QString raisonSociale)
{
    Structure * structure=new Structure();
    structure->ajouterChamp(tr("Nom"),new Texte(nom),0);
    structure->ajouterChamp(tr("Raison sociale"),new Texte(raisonSociale),1);
    return structure;
}

Champ* Organisme::logo(const QString url, const QString type)
{
    return new Image(url,type);
}

Champ* Organisme::membre(const QString fonction, QString card)
{
    Membre * membre=new Membre();
    membre->ajouterChamp(tr("card"),new Card(false,card),0);
    membre->ajouterChamp(tr("fonction"),new Texte(fonction),1);
    return membre;
}


void Organisme::creerChamp(const QString& nomChamp, const QString& type)
{
    QPair<Champ*,int> pa = Contact::creerChampFromType(type);
    Champ* champ=pa.first;
    int p=pa.second;
    if(type==tr("nom")) {champ=gnom();p=0;}
    else if(type==tr("logo")) {champ=logo();p=3;}
    else if(type==tr("membre")) {champ=membre();p=4;}
    ajouterChamp(nomChamp,champ,p);
}
