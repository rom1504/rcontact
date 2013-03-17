#include "structure.h"
#include <QStringList>

Structure::Structure()
{
}

Structure::~Structure()
{

}


void Structure::ajouterChamp(const QString & nomChamp,Champ * valeurChamp)
{
    mChamps.insert(nomChamp,valeurChamp);
}

int Structure::supprimerChamp(const QString & nomChamp, Champ * valeurChamp)
{
    return mChamps.remove(nomChamp,valeurChamp);
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

bool Structure::operator==(const Champ & t) const
{
    return toString()==t.toString();
}

QString Structure::toString() const
{
    QString s="";
    QStringList ks=mChamps.keys();
    for (int i = 0; i < ks.size(); ++i)
    {
        QList<Champ*> vs=mChamps.values(ks[i]);
        for (int j = 0; j < vs.size(); ++j)
        {
            s+=ks[i]+":"+vs[j]->toString()+";";
        }
    }
    return s;
}
