#include "structure.h"
#include "texte.h"
#include <QStringList>

Structure::Structure(QObject *parent) : Champ(parent)
{

}

Structure::Structure(const Structure & s,QObject * parent) : Champ(parent),mChamps(s.mChamps)
{

}

void Structure::ajouterChamp(const QString & nomChamp,Champ * valeurChamp)
{
    mChamps.insert(nomChamp,valeurChamp);
    emit dataChanged();
    connect(valeurChamp,SIGNAL(dataChanged()),this,SIGNAL(dataChanged()));
}

int Structure::supprimerChamp(const QString & nomChamp, Champ * valeurChamp)
{
    int n=mChamps.remove(nomChamp,valeurChamp);
    emit dataChanged();
    return n;
}

int Structure::supprimerChamp(const int index)
{
    QPair<QString,Champ*> p=(*this)[index];
    return supprimerChamp(p.first,p.second);
}


bool Structure::operator==(const Structure & c) const
{// pas bon
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

/**
 * @brief nombreValeurs
 * @return le nombre de valeur totales
 */
int Structure::nombreValeurs() const
{
    return mChamps.count();
}

QString Structure::toString() const
{
    QString s="";
    QStringList ks=mChamps.uniqueKeys();
    for (int i = 0; i < ks.size(); ++i)
    {
        QList<Champ*> vs=mChamps.values(ks[i]);
        for (int j = 0; j < vs.size(); ++j)
        {
//            s+=ks[i]+":"+vs[j]->toString()+";";
            s+=vs[j]->toString()+" ";
        }
    }
    return s;
}

QVariant Structure::toVariant()
{
    return QVariant::fromValue(this);
}

bool Structure::fromVariant(const QVariant v)
{
    mChamps=v.value<Structure*>()->mChamps;
    emit dataChanged();
    return true;
}

const QPair<QString,Champ*> Structure::operator[](const int n) const
{
    return qMakePair((mChamps.keys())[n],(mChamps.values())[n]);
}

bool Structure::fromString(const QString s) // pas utilisé normalement...
{
    if(s.length()!=0)
    {
        QString s2=s;
        s2.remove(s.length()-1,1);
        QStringList l=s2.split(";");
        for (int i = 0; i < l.size(); ++i)
        {
            QStringList l2=l[i].split(":");
            Texte * t=new Texte(); // à changer
            t->fromString(l2[1]);
            ajouterChamp(l2[0],t);
        }
    }
    emit dataChanged();
    return true;
}
