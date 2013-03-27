#include "personne.h"

Personne::Personne(QObject * parent) : Contact(parent)
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

Champ* Personne::gnom(const QString nom, const QString prenom, const QString prefixe, const QString surnom)
{
    Structure * structure=new Structure();
    structure->ajouterChamp("Préfixe",new Texte(prefixe));
    structure->ajouterChamp("Nom",new Texte(nom));
    structure->ajouterChamp("Prénom",new Texte(prenom));
    structure->ajouterChamp("Surnom",new Texte(surnom));
    return structure;
}

Champ* Personne::sexe(const QString sexe)
{
    return new Enum(sexe);
}

Champ* Personne::photo(const QString url, const QString type)
{
    Structure * structure=new Structure();
    structure->ajouterChamp("type",new Enum(type));
    structure->ajouterChamp("url",new Url(url));
    return structure;
}

Champ* Personne::organisation(Card *card)
{
    return card;
}

void Personne::creerChamp(const QString& nomChamp, const QString& type)
{
    Champ* champ = Contact::creerChampFromType(type);

    if(type=="nom") champ=gnom();
    else if(type=="sexe") champ=sexe();
    else if(type=="photo") champ=photo();
    else if(type=="organisation") champ=organisation();

    ajouterChamp(nomChamp, champ);
}
