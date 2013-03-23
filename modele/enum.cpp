#include "enum.h"

QStringList Enum::mEnumTypeListe;


QList<QStringList> Enum::mEnumListe;

void Enum::remplirEnums()
{
    mEnumTypeListe<<"typeImage";
    QStringList typeImage;
    typeImage<<"JPEG"<<"GIF"<<"PNG";
    mEnumListe<<typeImage;

    mEnumTypeListe<<"typeSite";
    QStringList typeSite;
    typeSite<<"web"<<"facebook"<<"google";
    mEnumListe<<typeSite;

    mEnumTypeListe<<"endroit";
    QStringList endroit;
    endroit<<"work"<<"home";
    mEnumListe<<endroit;

    mEnumTypeListe<<"typeTel";
    QStringList typeTel;
    typeTel<<"fixe"<<"cellulaire";
    mEnumListe<<typeTel;

    mEnumTypeListe<<"typeDonnees";
    QStringList typeDonnees;
    typeDonnees<<"voice"<<"data";
    mEnumListe<<typeDonnees;


    mEnumTypeListe<<"sexe";
    QStringList sexe;
    sexe<<"homme"<<"femme";
    mEnumListe<<sexe;
};

Enum::Enum(const int enum_,const int valeur) : mEnum(enum_),mValeur(valeur)
{

}


Enum::Enum(const QString s)
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

QVariant Enum::toVariant() const
{
    return QVariant::fromValue(*this);
}

bool Enum::fromVariant(const QVariant v)
{
   mEnum=v.value<Enum>().mEnum;
   mValeur=v.value<Enum>().mValeur;
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

Enum::~Enum()
{

}
