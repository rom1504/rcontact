#include "enum.h"

QStringList Enum::mEnumTypeListe;


QList<QStringList> Enum::mEnumListe;

void Enum::remplirEnums()
{
    mEnumTypeListe<<tr("typeImage");
    QStringList typeImage;
    typeImage<<tr("JPEG")<<tr("GIF")<<tr("PNG");
    mEnumListe<<typeImage;

    mEnumTypeListe<<tr("typeSite");
    QStringList typeSite;
    typeSite<<tr("web")<<tr("facebook")<<tr("google");
    mEnumListe<<typeSite;

    mEnumTypeListe<<tr("endroit");
    QStringList endroit;
    endroit<<tr("work")<<tr("home");
    mEnumListe<<endroit;

    mEnumTypeListe<<tr("typeTel");
    QStringList typeTel;
    typeTel<<tr("fixe")<<tr("cellulaire");
    mEnumListe<<typeTel;

    mEnumTypeListe<<tr("typeDonnees");
    QStringList typeDonnees;
    typeDonnees<<tr("voice")<<tr("data");
    mEnumListe<<typeDonnees;


    mEnumTypeListe<<tr("sexe");
    QStringList sexe;
    sexe<<tr("homme")<<tr("femme");
    mEnumListe<<sexe;
}

Enum::Enum(const int enum_,const int valeur,QObject * parent) : Champ(parent),mEnum(enum_),mValeur(valeur)
{

}

Enum::Enum(const Enum & e,QObject * parent) : Champ(parent),mEnum(e.mEnum),mValeur(e.mValeur)
{

}


Enum::Enum(const QString s, QObject *parent) : Champ(parent)
{
    if(!fromString(s))
    {
        mEnum=0;
        mValeur=0;
    }
}

int Enum::valeur() const
{
    return mValeur;
}

int Enum::getEnum() const
{
    return mEnum;
}

QStringList Enum::valeursPossibles() const
{
    return mEnumListe[mEnum];
}

QVariant Enum::toVariant()
{
    return QVariant::fromValue(this);
}

bool Enum::fromVariant(const QVariant v)
{
   mEnum=v.value<Enum*>()->mEnum;
   mValeur=v.value<Enum*>()->mValeur;
   return true;
}

bool Enum::operator==(const Enum & c) const
{
    return mEnum==c.mEnum && mValeur==c.mValeur;
}

QString Enum::toString() const
{
    return mEnumListe[mEnum][mValeur];
}

bool Enum::fromString(const QString s)
{
    for (int i = 0; i < mEnumTypeListe.size(); ++i)
    {
        for (int j = 0; j < (mEnumListe[i]).size(); ++j)
        {
            if(mEnumListe[i][j]==s)
            {
                mEnum=i;
                mValeur=j;
                return true;
            }
        }
    }
    return false;
}
