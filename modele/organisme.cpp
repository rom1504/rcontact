#include "organisme.h"

Organisme::Organisme(QObject * parent) : Contact(parent)
{
}

Contact* Organisme::creerDefaut()
{
    Contact * nouveau = new Organisme();
    nouveau->creerChamp("nom","nom");
    nouveau->creerChamp("tel","tel");
    nouveau->creerChamp("adresse","adresse");
    nouveau->creerChamp("email","email");
    nouveau->creerChamp("site","site");
    nouveau->creerChamp("logo","logo");
    nouveau->creerChamp("membre","membre");
    nouveau->creerChamp("date MAJ","date MAJ");
    nouveau->creerChamp("note","note");
    return nouveau;
}

Champ* Organisme::gnom(const QString nom,const QString raisonSociale)
{
    Structure * structure=new Structure();
    structure->ajouterChamp("Nom",new Texte(nom));
    structure->ajouterChamp("Raison sociale",new Texte(raisonSociale));
    return structure;
}

Champ* Organisme::logo(const QString url, const QString type)
{
    Structure * structure=new Structure();
    structure->ajouterChamp("type",new Enum(type));
    structure->ajouterChamp("url",new Url(url));
    return structure;
}

Champ* Organisme::membre(const QString fonction, Card *card)
{
    Structure * structure=new Structure();
    structure->ajouterChamp("card",card);
    structure->ajouterChamp("fonction",new Texte(fonction));
    return structure;
}


void Organisme::creerChamp(const QString& nomChamp, const QString& type)
{
    Champ* champ = Contact::creerChampFromType(type);

    if(type=="nom") champ=gnom();
    else if(type=="logo") champ=logo();
    else if(type=="membre") champ=membre();
    ajouterChamp(nomChamp, champ);
}
