#include "personne.h"
#include "card.h"
#include "enum.h"
#include "loc.h"
#include "structure.h"
#include "texte.h"
#include "timestamp.h"
#include "url.h"

Personne::Personne()
{
}

Contact* Personne::creerDefaut()
{
    Contact * nouveau = new Personne();
    nouveau->creerChamp("nom","nom");
    nouveau->creerChamp("sexe","sexe");
    nouveau->creerChamp("tel","tel");
    nouveau->creerChamp("adresse","adresse");
    nouveau->creerChamp("email","email");
    nouveau->creerChamp("site","site");
    nouveau->creerChamp("photo","photo");
    nouveau->creerChamp("organisation","organisation");
    nouveau->creerChamp("type","type");
    nouveau->creerChamp("date MAJ","date MAJ");
    nouveau->creerChamp("note","note");
    return nouveau;
}

void Personne::creerChamp(const QString& nom, const QString& type)
{
    Champ* champ = creerChampFromType(type);

    if(type=="nom")
    {
        Structure * structure=new Structure();
        structure->ajouterChamp("Préfixe",new Texte());
        structure->ajouterChamp("Nom",new Texte("Nom"));
        structure->ajouterChamp("Prénom",new Texte("Prénom"));
        structure->ajouterChamp("Surnom",new Texte());
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
