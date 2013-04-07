#include "adresse.h"
#include <QStringList>
#include "texte.h"
#include "loc.h"
#include "enum.h"

Adresse::Adresse(QObject *parent) :
    StructureOuTexte(parent)
{
}

Adresse::Adresse(const QString rue,const QString zipcode,const QString localite,const QString region,const QString pays,const QString type,Loc * geo,QObject *parent) :
    StructureOuTexte(parent)
{
    ajouterChamp(tr("type"),new Enum(type),0);
    ajouterChamp(tr("rue"),new Texte(rue),1);
    ajouterChamp(tr("zipcode"),new Texte(zipcode),2);
    ajouterChamp(tr("localité"),new Texte(localite),3);
    ajouterChamp(tr("Région"),new Texte(region),4);
    ajouterChamp(tr("pays"),new Texte(pays),5);
    ajouterChamp(tr("geo"),geo,6);
}

QString Adresse::toString() const
{
    return (avoirChamp(tr("rue"))+" "+avoirChamp(tr("zipcode"))+" "+avoirChamp(tr("localité"))+" "+avoirChamp(tr("Région"))+" "+avoirChamp(tr("pays"))+" "+avoirChamp(tr("géo"))).trimmed();
}

QString unParseString(QString s);

//the post office box; the extended address; the street
//address; the locality (e.g., city); the region (e.g., state or
//province); the postal code; the country name
QString Adresse::toVCard() const
{
    return ";TYPE="+avoirChamp(tr("type"))+":;;"+unParseString(avoirChamp(tr("rue")))+";"+unParseString(avoirChamp(tr("localité")))+";"+
            unParseString(avoirChamp(tr("Région")))+";"+avoirChamp(tr("zipcode"))+";"+unParseString(avoirChamp(tr("pays")));
}

bool Adresse::fromString(const QString s)
{
    if(toString()!=s)
    {
        QStringList l=s.split(" ");
        vider();

        // à améliorer ou bien repasser en juste Structure ?
        ajouterChamp(tr("rue"),new Texte(s),0);
        ajouterChamp(tr("type"),new Enum("work"),1);
        ajouterChamp(tr("zipcode"),new Texte(""),2);
        ajouterChamp(tr("localité"),new Texte(""),3);
        ajouterChamp(tr("Région"),new Texte(""),4);
        ajouterChamp(tr("pays"),new Texte(""),5);
        ajouterChamp(tr("geo"),new Loc(),6);
        return true;
    }
    return false;
}

