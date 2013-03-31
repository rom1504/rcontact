#include "structure.h"
#include "texte.h"
#include <QIcon>
#include <QStringList>
#include <QPainter>
#include <algorithm>

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

const Champ* Structure::operator[](const QString s) const
{
    return mChamps.value(s,NULL);
}

void Structure::vider()
{
    mChamps.clear();
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
            if(QString(vs[j]->metaObject()->className())!="Enum") s+=vs[j]->toString()+" ";
    }
    return s.trimmed();
}

QVariant Structure::image()
{

    QList<QPixmap> t_images;//list with all the Pictures, PicA, PicB, Pic...
    const int S_iconSize = 15;     //The pictures are all quadratic.


    QList<Champ*> vs=mChamps.values();
    for (int j = 0; j < vs.size(); ++j)
    {
        if(vs[j]->image().isValid())
            t_images<<vs[j]->image().value<QIcon>().pixmap(S_iconSize,S_iconSize);
    }
    if(t_images.length()==0) return QVariant();
    QImage resultImage(S_iconSize*t_images.size(), S_iconSize, QImage::Format_ARGB32_Premultiplied);
    QPainter painter;

    painter.begin(&resultImage);
    for(int i=0; i < t_images.size(); ++i)
    {
        painter.drawImage(S_iconSize*i, 0, t_images.at(i).toImage(), 0, 0, S_iconSize, S_iconSize, Qt::AutoColor);
    }
    painter.end();

    QPixmap resultingCollagePixmap = QPixmap::fromImage(resultImage);
    return resultingCollagePixmap;
}

void Structure::remplacer(QString s,Champ * c)
{
    mChamps.replace(s,c);
}

QVariant Structure::toVariant()
{
    return QVariant::fromValue(this);
}

QString Structure::avoirChamp(QString nom) const
{
    const Champ * c=operator[](nom);
    if(c==NULL) return "";
    return c->toString();
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
