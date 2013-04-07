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
    ajouterChamp(tr("type"),new Enum(type));
    ajouterChamp(tr("rue"),new Texte(rue));
    ajouterChamp(tr("zipcode"),new Texte(zipcode));
    ajouterChamp(tr("localité"),new Texte(localite));
    ajouterChamp(tr("Région"),new Texte(region));
    ajouterChamp(tr("pays"),new Texte(pays));
    ajouterChamp(tr("geo"),geo);
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
        ajouterChamp(tr("rue"),new Texte(s));
        ajouterChamp(tr("type"),new Enum("work"));
        ajouterChamp(tr("zipcode"),new Texte(""));
        ajouterChamp(tr("localité"),new Texte(""));
        ajouterChamp(tr("Région"),new Texte(""));
        ajouterChamp(tr("pays"),new Texte(""));
        ajouterChamp(tr("geo"),new Loc());
        return true;
    }
    return false;
}

