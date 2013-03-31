#include "organisme.h"
#include <QPixmap>

Organisme::Organisme(QObject * parent) : Contact(parent)
{
}

QVariant Organisme::image() const
{
    Champ * champ=mChamps.value("logo",NULL);
    if(champ==NULL) return QVariant();
    QVariant v=champ->image();
    if(!(v.isValid())) return QVariant();
    QPixmap p=champ->image().value<QPixmap>();
    if(p.isNull()) return QVariant();
    p.scaledToWidth(20);
    return p;
}

Organisme *Organisme::creerDefaut()
{
    Organisme * nouveau = new Organisme();
    nouveau->creerChamp(tr("nom"),tr("nom"));
    nouveau->creerChamp(tr("tel"),tr("tel"));
    nouveau->creerChamp(tr("adresse"),tr("adresse"));
    nouveau->creerChamp(tr("email"),tr("email"));
    nouveau->creerChamp(tr("site"),tr("site"));
    nouveau->creerChamp(tr("logo"),tr("logo"));
    nouveau->creerChamp(tr("membre"),tr("membre"));
    nouveau->creerChamp(tr("date MAJ"),tr("date MAJ"));
    nouveau->creerChamp(tr("note"),tr("note"));
    return nouveau;
}

Champ* Organisme::gnom(const QString nom,const QString raisonSociale)
{
    Structure * structure=new Structure();
    structure->ajouterChamp(tr("Nom"),new Texte(nom));
    structure->ajouterChamp(tr("Raison sociale"),new Texte(raisonSociale));
    return structure;
}

Champ* Organisme::logo(const QString url, const QString type)
{
    Structure * structure=new Structure();
    structure->ajouterChamp(tr("type"),new Enum(type));
    structure->ajouterChamp(tr("url"),new Url(url));
    return structure;
}

Champ* Organisme::membre(const QString fonction, Card *card)
{
    Structure * structure=new Structure();
    structure->ajouterChamp(tr("card"),card);
    structure->ajouterChamp(tr("fonction"),new Texte(fonction));
    return structure;
}


void Organisme::creerChamp(const QString& nomChamp, const QString& type)
{
    Champ* champ = Contact::creerChampFromType(type);

    if(type==tr("nom")) champ=gnom();
    else if(type==tr("logo")) champ=logo();
    else if(type==tr("membre")) champ=membre();
    ajouterChamp(nomChamp, champ);
}
