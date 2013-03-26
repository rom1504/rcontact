#include "contact.h"
#include "../modele/card.h"
#include "../modele/enum.h"
#include "../modele/loc.h"
#include "../modele/structure.h"
#include "../modele/texte.h"
#include "../modele/timestamp.h"
#include "../modele/url.h"

Contact::Contact()
{

}

Contact::~Contact()
{

}

Contact::Contact(const Contact & c)
{
    mChamps=c.mChamps;
}

void Contact::ajouterChamp(const QString & nomChamp,Champ * valeurChamp)
{
    mChamps.insert(nomChamp,valeurChamp);
}

void Contact::ajouterChamp(const QString &nomChamp, const QString& type)
{
    Champ * champ=NULL;
    /*if(type=="card") champ=new Card();
    else if(type=="enum") champ=new Enum();
    else if(type=="loc") champ=new Loc();
    else if(type=="structure") champ=new Structure();
    else if(type=="texte") champ=new Texte();
    else if(type=="timestamp") champ=new Timestamp();
    else if(type=="url") champ=new Url();
    else */if(type=="nom")
    {
        Structure * structure=new Structure();
        structure->ajouterChamp("Préfixe",new Texte());
        structure->ajouterChamp("Nom",new Texte("Nom"));
        structure->ajouterChamp("Prénom",new Texte("Prénom"));
        structure->ajouterChamp("Surnom",new Texte());
        champ=structure;
    }
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
    else if(type=="adresse")
    {
        Structure * structure=new Structure();
        structure->ajouterChamp("type",new Enum("work"));
        structure->ajouterChamp("rue",new Texte());
        structure->ajouterChamp("zipcode",new Texte());
        structure->ajouterChamp("localité",new Texte());
        structure->ajouterChamp("Région",new Texte());
        structure->ajouterChamp("pays",new Texte());
        structure->ajouterChamp("geo",new Loc());
        champ=structure;
    }
    else if(type=="email")
    {
        Structure * structure=new Structure();
        structure->ajouterChamp("nom",new Texte());
        structure->ajouterChamp("domaine",new Texte());
        structure->ajouterChamp("extension",new Texte());
        champ=structure;
    }
    else if(type=="site")
    {
        Structure * structure=new Structure();
        structure->ajouterChamp("type",new Enum("web"));
        structure->ajouterChamp("url",new Url());
        champ=structure;
    }
    else if(type=="photo")
    {
        Structure * structure=new Structure();
        structure->ajouterChamp("type",new Enum("JPEG"));
        structure->ajouterChamp("url",new Url());
    }
    else if(type=="organisation") champ=new Card();
    else if(type=="type") champ=new Texte();
    else if(type=="date MAJ") champ=new Timestamp();
    else if(type=="note") champ=new Texte();
    ajouterChamp(nomChamp,champ);
}


bool Contact::operator==(const Contact & c) const
{ // pas bon
    bool b = false; // Mis à true si on trouve une correspondance
    QMultiMap<QString,Champ*>::const_iterator it1 = mChamps.begin();
    while (it1 != mChamps.end() && !b)
    {
        QMultiMap<QString,Champ*>::const_iterator it2 = c.mChamps.begin();
        while (it2 != c.mChamps.end() && !b)
        {
            // Comparaison des clés et des valeurs.
            b = (it1.key() == it2.key()) && (*(it1.value()) == *(it2.value()));
            it2++;
        }
        it1++;
    }
    return b;
}


QString Contact::nom() const
{
    return mChamps.value("nom")->toString();
}

int Contact::nombreValeurs() const
{
    return mChamps.count();
}

bool Contact::aNom() const
{
    return mChamps.contains("nom");
}


const QPair<QString,Champ*> Contact::operator[](const int n) const
{
    return qMakePair((mChamps.keys())[n],(mChamps.values())[n]);
}

int Contact::supprimerChamp(const int index)
{
    QPair<QString,Champ*> p=(*this)[index];
    return supprimerChamp(p.first,p.second);
}

int Contact::supprimerChamp(const QString & nomChamp,Champ * valeurChamp)
{
    int nb=mChamps.remove(nomChamp,valeurChamp);// pas bon : que si même pointeur... : à faire en utilisant les iterateurs.
    //: en fait ça va : passer en privé ?
    return nb;
}
