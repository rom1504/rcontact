#include "organisme.h"
#include "card.h"
#include "enum.h"
#include "loc.h"
#include "structure.h"
#include "texte.h"
#include "timestamp.h"
#include "url.h"

Organisme::Organisme()
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


void Organisme::creerChamp(const QString& nom, const QString& type)
{
    Champ* champ = creerChampFromType(type);

    if(type=="nom")
    {
        Structure * structure=new Structure();
        structure->ajouterChamp("Nom",new Texte("Nom"));
        structure->ajouterChamp("Raison sociale",new Texte("Raison sociale"));
        champ=structure;
    }
    else if(type=="sexe") champ=new Enum("homme");
    else if(type=="photo")
    {
        Structure * structure=new Structure();
        structure->ajouterChamp("type",new Enum("JPEG"));
        structure->ajouterChamp("url",new Url());
    }
    else if(type=="organisation") champ=new Card();
    else if(type=="type") champ=new Texte();

    ajouterChamp(nom, champ);
}
