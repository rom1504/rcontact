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
    for(int i=0;i<mChampsListe.size();i++)
    {
        r+="<"+QString(mChampsListe[i].valeur->metaObject()->className())+" nomChamp=\""+mChampsListe[i].nom+"\" priorite=\""+QString::number(mChampsListe[i].priorite)+"\">";
        r+=mChampsListe[i].valeur->toXML();
        r+="</"+QString(mChampsListe[i].valeur->metaObject()->className())+">";
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
    if((champ=at(tr("email")))) r+="EMAIL"+champ->toVCard()+"\n";
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

void Contact::essayerEncore()
{
    QList<Champ*> vs=mChamps.values();
    std::for_each(vs.begin(),vs.end(),essayerEncore_);
}

void Contact::remplacer(QString s,Champ * c)
{
    QList<BChamp> nouveau;
    int p=0;
    for(int i=0;i<mChampsListe.size();i++)
    {
        if(mChampsListe[i].nom!=s) nouveau<<mChampsListe[i];
        else p=mChampsListe[i].priorite;
    }
    mChampsListe=nouveau;

    mChamps.remove(s);

    ajouterChamp(s,c,p);
}

void Contact::ajouterChamp(const QString & nomChamp, Champ* valeurChamp, int priorite)
{
    mChamps.insert(nomChamp,valeurChamp);


    int j=mChampsListe.size();
    for(int i=0;i<mChampsListe.size();i++)
    {
        if(mChampsListe[i].priorite>priorite)
        {
            j=i;
            break;
        }
    }
    BChamp bChamp;
    bChamp.nom=nomChamp;
    bChamp.valeur=valeurChamp;
    bChamp.priorite=priorite;
    mChampsListe.insert(j,bChamp);


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
    structure->ajouterChamp(tr("type"),new Enum(type),0);
    structure->ajouterChamp(tr("url"),new Url(url),1);
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

QPair<Champ*,int> Contact::creerChampFromType(const QString& type)
{
    Champ * champ=NULL;
    int p=0;
    if(type==tr("tel")) {champ=tel();p=5;}
    else if(type==tr("adresse")) {champ=adresse();p=6;}
    else if(type==tr("email")) {champ=email();p=7;}
    else if(type==tr("site")) {champ=site();p=8;}
    else if(type==tr("type")) {champ=gtype();p=9;}
    else if(type==tr("date")) {champ=date();p=10;}
    else if(type==tr("note")) {champ=note();p=11;}
    return qMakePair(champ,p);
}



QString Contact::nom() const
{
    const Champ * nom=at(tr("nom"));
    if(nom==NULL) return "";
    return nom->toString();
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
    BChamp b=mChampsListe[n];
    return qMakePair(b.nom,b.valeur);
}

int Contact::supprimerChamp(const int index)
{
    mChampsListe.removeAt(index);
    QPair<QString,Champ*> p=(*this)[index];
    int nb=mChamps.remove(p.first,p.second);
    emit dataChanged();
    return nb;
}
