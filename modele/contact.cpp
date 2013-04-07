#include "contact.h"
#include "card.h"
#include "enum.h"
#include "loc.h"
#include "structure.h"
#include "texte.h"
#include "timestamp.h"
#include "url.h"
#include "tel.h"
#include "adresse.h"
#include "email.h"
#include "grandtexte.h"

Contact::Contact(QObject *parent) : QObject(parent)
{

}

Contact::~Contact()
{

}

QString Contact::toXML() const
{
    QString r="";
    QList<QString> ks=mChamps.keys();
    QList<Champ*> vs=mChamps.values();
    for(int i=0;i<ks.size();i++)
    {
        r+="<"+QString(vs[i]->metaObject()->className())+" nomChamp=\""+ks[i]+"\">";
        r+=vs[i]->toXML();
        r+="</"+QString(vs[i]->metaObject()->className())+">";
    }
    return r;
}

QString parseString(QString s);

QString unParseString(QString s);

QString Contact::toVCard() const
{
    QString r="";
    r+=QString("BEGIN:VCARD\n");
    r+=QString("VERSION:4.0\n");
    r+=QString("KIND:")+(QString(metaObject()->className())=="Personne" ? "individual" : "organism")+"\n";
    const Champ * champ=NULL;
    if((champ=at(tr("nom"))))
    {
        r+="FN:"+champ->toString()+"\n";
        r+="N"+champ->toVCard()+"\n";
    }
    if((champ=at(tr("adresse")))) r+="ADR"+champ->toVCard()+"\n";
    if((champ=at(tr("tel")))) r+="TEL"+champ->toVCard()+"\n";
    if((champ=at(tr("mail")))) r+="EMAIL"+champ->toVCard()+"\n";
    if((champ=at(tr("date de naissance")))) r+="BDAY"+champ->toVCard()+"\n";
    if((champ=at(tr("url")))) r+="URL"+champ->toVCard()+"\n";
    if((champ=at(tr("photo")))) r+="PHOTO"+champ->toVCard()+"\n";
    if((champ=at(tr("organisation")))) r+="ORG"+champ->toVCard()+"\n";
    if((champ=at(tr("membre")))) r+="MEMBER"+champ->toVCard()+"\n";
    if((champ=at(tr("logo")))) r+="LOGO"+champ->toVCard()+"\n";
    if((champ=at(tr("note")))) r+="NOTE"+champ->toVCard()+"\n";
    r+="END:VCARD\n";
    return r;
}

void essayerEncore_(Champ * c)
{
    c->essayerEncore();
}

// car pas dispo sur la yaka (??)
template<class InputIterator, class Function>
  Function for_each(InputIterator first, InputIterator last, Function fn)
{
  while (first!=last) {
    fn (*first);
    ++first;
  }
  return fn;      // or, since C++11: return move(fn);
}

void Contact::essayerEncore()
{
    QList<Champ*> vs=mChamps.values();
    for_each(vs.begin(),vs.end(),essayerEncore_);
}

void Contact::remplacer(QString s,Champ * c)
{
    mChamps.replace(s,c);
}

void Contact::ajouterChamp(const QString & nomChamp, Champ* valeurChamp)
{
    mChamps.insert(nomChamp,valeurChamp);
    emit dataChanged();
    connect(valeurChamp,SIGNAL(dataChanged()),this,SIGNAL(dataChanged()));
}

Champ* Contact::tel(const QString numero, const QString type, const QString typeTel, const QString typeDonnees)
{
    return new Tel(numero,type,typeTel,typeDonnees);
}

Champ* Contact::adresse(const QString rue,const QString zipcode,const QString localite,const QString region,const QString pays,const QString type,Loc * geo)
{
    return new Adresse(rue,zipcode,localite,region,pays,type,geo);
}

Champ* Contact::email(const QString nom,const QString domaine,const QString extension)
{
    return new Email(nom,domaine,extension);
}

Champ* Contact::site(const QString url, const QString type)
{
    Structure * structure=new Structure();
    structure->ajouterChamp(tr("type"),new Enum(type));
    structure->ajouterChamp(tr("url"),new Url(url));
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
    return new GrandTexte(note);
}

Champ* Contact::url(const QString texte)
{
    return new Url(texte);
}

const Champ* Contact::at(const QString s) const
{
    return mChamps.value(s,NULL);
}

const Champ* Contact::operator[](const QString s) const
{
    return at(s);
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
    if(type==tr("tel")) champ=tel();
    else if(type==tr("adresse")) champ=adresse();
    else if(type==tr("email")) champ=email();
    else if(type==tr("site")) champ=site();
    else if(type==tr("type")) champ=gtype();
    else if(type==tr("date")) champ=date();
    else if(type==tr("note")) champ=note();
    return champ;
}



QString Contact::nom() const
{
    return mChamps.value(tr("nom"))->toString();
}

int Contact::nombreValeurs() const
{
    return mChamps.count();
}

bool Contact::aNom() const
{
    return mChamps.contains(tr("nom"));
}

const QPair<QString,Champ*> Contact::operator[](const int n) const
{
    QList<QString> lk=(mChamps.keys());
    QList<Champ*> lv=(mChamps.values());
    return  qMakePair(lk.length()<=n ? "" : lk[n],lv.length()<=n ? NULL : lv[n]);
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
    emit dataChanged();
    return nb;
}
