#include "personne.h"
#include "nom.h"

Personne::Personne(QObject * parent) : Contact(parent)
{
}

Contact* Personne::creerDefaut()
{
    Contact * nouveau = new Personne();
    nouveau->creerChamp(tr("nom"),tr("nom"));
    nouveau->creerChamp(tr("sexe"),tr("sexe"));
    nouveau->creerChamp(tr("tel"),tr("tel"));
    nouveau->creerChamp(tr("adresse"),tr("adresse"));
    nouveau->creerChamp(tr("email"),tr("email"));
    nouveau->creerChamp(tr("site"),tr("site"));
    nouveau->creerChamp(tr("photo"),tr("photo"));
    nouveau->creerChamp(tr("organisation"),tr("organisation"));
    nouveau->creerChamp(tr("type"),tr("type"));
    nouveau->creerChamp(tr("date MAJ"),tr("date MAJ"));
    nouveau->creerChamp(tr("note"),tr("note"));
    return nouveau;
}

Champ* Personne::gnom(const QString nom, const QString prenom, const QString prefixe, const QString surnom)
{
    Nom * snom=new Nom();
    snom->ajouterChamp(tr("Préfixe"),new Texte(prefixe));
    snom->ajouterChamp(tr("Nom"),new Texte(nom));
    snom->ajouterChamp(tr("Prénom"),new Texte(prenom));
    snom->ajouterChamp(tr("Surnom"),new Texte(surnom));
    return snom;
}

Champ* Personne::sexe(const QString sexe)
{
    return new Enum(sexe);
}

Champ* Personne::photo(const QString url, const QString type)
{
    Structure * structure=new Structure();
    structure->ajouterChamp(tr("type"),new Enum(type));
    structure->ajouterChamp(tr("url"),new Url(url));
    return structure;
}

Champ* Personne::organisation(Card *card)
{
    return card;
}

void Personne::creerChamp(const QString& nomChamp, const QString& type)
{
    Champ* champ = Contact::creerChampFromType(type);

    if(type==tr("nom")) champ=gnom();
    else if(type==tr("sexe")) champ=sexe();
    else if(type==tr("photo")) champ=photo();
    else if(type==tr("organisation")) champ=organisation();

    ajouterChamp(nomChamp, champ);
}
