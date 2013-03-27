#include "contact.h"
#include "card.h"
#include "enum.h"
#include "loc.h"
#include "structure.h"
#include "texte.h"
#include "timestamp.h"
#include "url.h"

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


void Contact::ajouterChamp(const QString & nomChamp, Champ* valeurChamp)
{
    mChamps.insert(nomChamp,valeurChamp);
}

Champ* Contact::tel(const QString numero, const QString type, const QString typeTel, const QString typeDonnees)
{
    Structure * structure=new Structure();
    structure->ajouterChamp("type",new Enum(type));
    structure->ajouterChamp("type tel",new Enum(typeTel));
    structure->ajouterChamp("type données",new Enum(typeDonnees));
    structure->ajouterChamp("n°",new Texte(numero));
    return structure;
}

Champ* Contact::adresse(const QString rue,const QString zipcode,const QString localite,const QString region,const QString pays,const QString type,Loc * geo)
{
    Structure * structure=new Structure();
    structure->ajouterChamp("type",new Enum(type));
    structure->ajouterChamp("rue",new Texte(rue));
    structure->ajouterChamp("zipcode",new Texte(zipcode));
    structure->ajouterChamp("localité",new Texte(localite));
    structure->ajouterChamp("Région",new Texte(region));
    structure->ajouterChamp("pays",new Texte(pays));
    structure->ajouterChamp("geo",geo);
    return structure;
}

Champ* Contact::email(const QString nom,const QString domaine,const QString extension)
{
    Structure * structure=new Structure();
    structure->ajouterChamp("nom",new Texte(nom));
    structure->ajouterChamp("domaine",new Texte(domaine));
    structure->ajouterChamp("extension",new Texte(extension));
    return structure;
}

Champ* Contact::site(const QString url, const QString type)
{
    Structure * structure=new Structure();
    structure->ajouterChamp("type",new Enum(type));
    structure->ajouterChamp("url",new Url(url));
    return structure;
}

Champ* Contact::gtype(const QString type)
{
    return new Texte(type);
}

Champ* Contact::date(const QString timestamp)
{
    return new Timestamp(timestamp);
}

Champ* Contact::note(const QString note)
{
    return new Texte(note);
}

Champ* Contact::url(const QString texte)
{
    return new Url(texte);
}

const Champ* Contact::operator[](const QString s) const
{
    return mChamps.value(s,NULL);
}

Champ* Contact::creerChampFromType(const QString& type)
{
    Champ * champ=NULL;
    /*if(type=="card") champ=new Card();
    else if(type=="enum") champ=new Enum();
    else if(type=="loc") champ=new Loc();
    else if(type=="structure") champ=new Structure();
    else if(type=="texte") champ=new Texte();
    else if(type=="timestamp") champ=new Timestamp();
    else if(type=="url") champ=new Url();
    else */
    if(type=="tel") champ=tel();
    else if(type=="adresse") champ=adresse();
    else if(type=="email") champ=email();
    else if(type=="site") champ=site();
    else if(type=="type") champ=gtype();
    else if(type=="date MAJ") champ=date();
    else if(type=="note") champ=note();
    return champ;
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
