#include "personne.h"
#include "nom.h"
#include "image.h"
#include <QPixmap>

Personne::Personne(QObject * parent) : Contact(parent)
{
}


QVariant Personne::image() const
{
    const Champ * champ=at("photo");
    if(champ==NULL) return QVariant();
    QVariant v=champ->image();
    if(!(v.isValid())) return QVariant();
    QPixmap p=champ->image().value<QPixmap>();
    if(p.isNull()) return QVariant();
    p=p.scaledToWidth(60);
    return p;
}


Personne *Personne::creerDefaut()
{
    Personne * nouveau = new Personne();
    nouveau->creerChamp(tr("nom"),tr("nom"));
//    nouveau->creerChamp(tr("sexe"),tr("sexe"));
//    nouveau->creerChamp(tr("tel"),tr("tel"));
//    nouveau->creerChamp(tr("adresse"),tr("adresse"));
//    nouveau->creerChamp(tr("email"),tr("email"));
//    nouveau->creerChamp(tr("site"),tr("site"));
//    nouveau->creerChamp(tr("photo"),tr("photo"));
//    nouveau->creerChamp(tr("organisation"),tr("organisation"));
//    nouveau->creerChamp(tr("type"),tr("type"));
//    nouveau->creerChamp(tr("date MAJ"),tr("date"));
//    nouveau->creerChamp(tr("note"),tr("note"));
    return nouveau;
}

Champ* Personne::gnom(const QString nom, const QString prenom, const QString prefixe, const QString surnom)
{
    return new Nom(nom,prenom,prefixe,surnom);
}

Champ* Personne::sexe(const QString sexe)
{
    return new Enum(sexe);
}


Champ* Personne::photo(const QString url, const QString type)
{
    return new Image(url,type);
}

Champ* Personne::organisation(QString card)
{
    return new Card(true,card);
}


void Personne::creerChamp(const QString& nomChamp, const QString& type)
{
    QPair<Champ*,int> pa = Contact::creerChampFromType(type);
    Champ* champ=pa.first;
    int p=pa.second;
    if(type==tr("nom")) {champ=gnom();p=0;}
    else if(type==tr("sexe")) {champ=sexe();p=2;}
    else if(type==tr("photo")) {champ=photo();p=3;}
    else if(type==tr("organisation")) {champ=organisation();p=4;}

    ajouterChamp(nomChamp,champ,p);
}
