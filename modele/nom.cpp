#include "nom.h"
#include <QStringList>
#include "texte.h"

Nom::Nom(QObject *parent) :
    StructureOuTexte(parent)
{
}

Nom::Nom(const QString nom, const QString prenom, const QString prefixe, const QString surnom)
{
    ajouterChamp(tr("Préfixe"),new Texte(prefixe));
    ajouterChamp(tr("Nom"),new Texte(nom));
    ajouterChamp(tr("Prénom"),new Texte(prenom));
    ajouterChamp(tr("Surnom"),new Texte(surnom));
}

QString Nom::toString() const
{
    return (avoirChamp(tr("Préfixe"))+" "+avoirChamp(tr("Prénom"))+" "+avoirChamp(tr("Nom"))+" "+avoirChamp(tr("Surnom"))).trimmed();
}

bool Nom::fromString(const QString s)
{
    if(s!=toString())
    {
        QStringList l=s.split(" ");
        vider();
        ajouterChamp(tr("Préfixe"),new Texte(l.length()>=4 ? l.takeFirst() : ""));
        ajouterChamp(tr("Prénom"),new Texte(l.length()>=1 ? l.takeFirst() : ""));
        ajouterChamp(tr("Nom"),new Texte(l.length()>=1 ? l.takeFirst() : ""));
        ajouterChamp(tr("Surnom"),new Texte(l.join(" ")));
        return true;
    }
    return false;
}

QString unParseString(QString s);

//            the Family Name, Given Name, Additional Names, Honorific
//               Prefixes, and Honorific Suffixes
QString Nom::toVCard() const
{
    return ":"+unParseString(avoirChamp(tr("Nom"))+";"+avoirChamp(tr("Prénom"))+";"+avoirChamp(tr("Surnom"))+";"+avoirChamp(tr("Préfixe"))+";");// ?
}
