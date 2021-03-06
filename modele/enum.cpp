#include "enum.h"
#include <QIcon>

QStringList Enum::mEnumTypeListe;


QList<QStringList> Enum::mEnumListe;

QList<QList<QIcon> > Enum::mIconeEnumListe;

void Enum::remplirEnums()
{
    mEnumTypeListe<<tr("typeImage");
    QStringList typeImage;
    typeImage<<tr("JPEG")<<tr("GIF")<<tr("PNG");
    mEnumListe<<typeImage;

    QList<QIcon> iconesTypeImage;
    iconesTypeImage<<QIcon()<<QIcon()<<QIcon();
    mIconeEnumListe<<iconesTypeImage;


    mEnumTypeListe<<tr("typeSite");
    QStringList typeSite;
    typeSite<<tr("web")<<tr("facebook")<<tr("google");
    mEnumListe<<typeSite;

    QList<QIcon> iconesTypeSite;
    iconesTypeSite<<QIcon(":/icones/web.png")<<QIcon(":/icones/facebook.png")<<QIcon(":/icones/googleplus.png");
    mIconeEnumListe<<iconesTypeSite;


    mEnumTypeListe<<tr("endroit");
    QStringList endroit;
    endroit<<tr("work")<<tr("home");
    mEnumListe<<endroit;

    QList<QIcon> iconesEndroit;
    iconesEndroit<<QIcon(":/icones/work.png")<<QIcon(":/icones/home.png");
    mIconeEnumListe<<iconesEndroit;


    mEnumTypeListe<<tr("typeTel");
    QStringList typeTel;
    typeTel<<tr("fixe")<<tr("cellulaire");
    mEnumListe<<typeTel;

    QList<QIcon> iconesTypeTel;
    iconesTypeTel<<QIcon(":/icones/fixe.png")<<QIcon(":/icones/mobile.png");
    mIconeEnumListe<<iconesTypeTel;


    mEnumTypeListe<<tr("typeDonnees");
    QStringList typeDonnees;
    typeDonnees<<tr("voice")<<tr("data");
    mEnumListe<<typeDonnees;

    QList<QIcon> iconesTypeDonnees;
    iconesTypeDonnees<<QIcon(":/icones/voice.png")<<QIcon(":/icones/data.png");
    mIconeEnumListe<<iconesTypeDonnees;


    mEnumTypeListe<<tr("sexe");
    QStringList sexe;
    sexe<<tr("homme")<<tr("femme");
    mEnumListe<<sexe;

    QList<QIcon> iconesSexe;
    iconesSexe<<QIcon(":/icones/homme.png")<<QIcon(":/icones/femme.png");
    mIconeEnumListe<<iconesSexe;
}

QVariant Enum::image() const
{
    if(mIconeEnumListe[mEnum][mValeur].isNull()) return QVariant();
    else return mIconeEnumListe[mEnum][mValeur];
}

Enum::Enum(const int enum_,const int valeur,QObject * parent) : Champ(parent),mEnum(enum_),mValeur(valeur)
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
