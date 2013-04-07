#include "structure.h"
#include "texte.h"
#include <QIcon>
#include <QStringList>
#include <QPainter>
#include <algorithm>

Structure::Structure(QObject *parent) : Champ(parent)
{

}

QString Structure::toXML() const
{
    QString r="";
    QList<QString> ks=mChamps.keys();
    QList<Champ*> vs=mChamps.values();
    for(int i=0;i<ks.size();i++)
    {
        r+="<"+QString(vs[i]->metaObject()->className())+" nomChamp=\""+ks[i]+"\">";
        r+=vs[i]->toXML();
        r+="</"+QString(vs[i]->metaObject()->className())+">";
    }
    return r;
}

void essayerEncore_(Champ * c);

// car pas dispo sur la yaka (??)
template<class InputIterator, class Function>
  Function for_each(InputIterator first, InputIterator last, Function fn)
{
  while (first!=last) {
    fn (*first);
    ++first;
  }
  return fn;      // or, since C++11: return move(fn);
}

void Structure::essayerEncore()
{
    QList<Champ*> vs=mChamps.values();
    for_each(vs.begin(),vs.end(),essayerEncore_);
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
QSize max(QSize,QSize);

QVariant Structure::image()
{

    QList<QPixmap> t_images;


    QList<Champ*> vs=mChamps.values();
    QSize M(0,0);
    for (int j = 0; j < vs.size(); ++j)
    {
        if(vs[j]->image().isValid())
        {
            QPixmap p=vs[j]->image().value<QPixmap>();
            if(p.isNull()) p=vs[j]->image().value<QIcon>().pixmap(15,15);
            if(!(p.isNull()))
            {
                t_images<<p;
                M=max(M,p.size());
            }
        }
    }
    if(t_images.length()==0) return QVariant();

    QImage resultImage(M.width()*t_images.size(), M.height(), QImage::Format_ARGB32_Premultiplied);
    resultImage.fill(Qt::transparent);
    QPainter painter;

    painter.begin(&resultImage);
    for(int i=0; i < t_images.size(); ++i)
    {
        painter.drawImage(M.width()*i, 0, t_images.at(i).toImage(), 0, 0, M.width(), M.height(), Qt::AutoColor);
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
