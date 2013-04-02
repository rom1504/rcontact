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
        r+="<"+QString(vs[i]->metaObject()->className())+" nomChamp=\""+ks[i]+"\">\n";
        r+=vs[i]->toXML()+"\n";
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
        r+="N:"+champ->toVCard()+"\n";
    }
    if((champ=at(tr("adresse")))) r+="ADR:"+unParseString(champ->toVCard())+"\n";
    if((champ=at(tr("tel")))) r+="TEL:"+champ->toVCard()+"\n";
    if((champ=at(tr("mail")))) r+="EMAIL:"+champ->toVCard()+"\n";
    if((champ=at(tr("date de naissance")))) r+="BDAY:"+champ->toVCard()+"\n";
    if((champ=at(tr("url")))) r+="URL:"+champ->toVCard()+"\n";
    if((champ=at(tr("photo")))) r+="PHOTO:"+champ->toVCard()+"\n";
    if((champ=at(tr("organisation")))) r+="ORG:"+champ->toVCard()+"\n";
    if((champ=at(tr("membre")))) r+="MEMBER:"+champ->toVCard()+"\n";
    if((champ=at(tr("logo")))) r+="LOGO:"+champ->toVCard()+"\n";
    if((champ=at(tr("note")))) r+="NOTE:"+unParseString(champ->toVCard())+"\n";
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
    mChamps.replace(s,c);
}

Contact::Contact(const Contact & c,QObject * parent=0) : QObject(parent)
{
    mChamps=c.mChamps;
}


void Contact::ajouterChamp(const QString & nomChamp, Champ* valeurChamp)
{
    mChamps.insert(nomChamp,valeurChamp);
    emit dataChanged();
    connect(valeurChamp,SIGNAL(dataChanged()),this,SIGNAL(dataChanged()));
}

Champ* Contact::tel(const QString numero, const QString type, const QString typeTel, const QString typeDonnees)
{
    Tel * tel=new Tel();
    tel->ajouterChamp(tr("type"),new Enum(type));
    tel->ajouterChamp(tr("type tel"),new Enum(typeTel));
    tel->ajouterChamp(tr("type données"),new Enum(typeDonnees));
    tel->ajouterChamp(tr("n°"),new Texte(numero));
    return tel;
}

Champ* Contact::adresse(const QString rue,const QString zipcode,const QString localite,const QString region,const QString pays,const QString type,Loc * geo)
{
    Adresse * adresse=new Adresse();
    adresse->ajouterChamp(tr("type"),new Enum(type));
    adresse->ajouterChamp(tr("rue"),new Texte(rue));
    adresse->ajouterChamp(tr("zipcode"),new Texte(zipcode));
    adresse->ajouterChamp(tr("localité"),new Texte(localite));
    adresse->ajouterChamp(tr("Région"),new Texte(region));
    adresse->ajouterChamp(tr("pays"),new Texte(pays));
    adresse->ajouterChamp(tr("geo"),geo);
    return adresse;
}

Champ* Contact::email(const QString nom,const QString domaine,const QString extension)
{
    Email * email=new Email();// dans constructeur ?
    email->ajouterChamp(tr("nom"),new Texte(nom));
    email->ajouterChamp(tr("domaine"),new Texte(domaine));
    email->ajouterChamp(tr("extension"),new Texte(extension));
    return email;
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
    return new Texte(note);
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
