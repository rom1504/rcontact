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
    for(int i=0;i<mChampsListe.size();i++)
    {
        r+="<"+QString(mChampsListe[i].valeur->metaObject()->className())+" nomChamp=\""+mChampsListe[i].nom+"\" priorite=\""+QString::number(mChampsListe[i].priorite)+"\">";
        r+=mChampsListe[i].valeur->toXML();
        r+="</"+QString(mChampsListe[i].valeur->metaObject()->className())+">";
    }
    return r;
}

void essayerEncore_(Champ * c);


void Structure::essayerEncore()
{
    QList<Champ*> vs=mChamps.values();
    std::for_each(vs.begin(),vs.end(),essayerEncore_);
}

void Structure::ajouterChamp(const QString & nomChamp, Champ * valeurChamp, int priorite)
{
    mChamps.insert(nomChamp,valeurChamp);


    int j=mChampsListe.size();
    for(int i=0;i<mChampsListe.size();i++)
    {
        if(mChampsListe[i].priorite>priorite)
        {
            j=i;
            break;
        }
    }
    BChamp bChamp;
    bChamp.nom=nomChamp;
    bChamp.valeur=valeurChamp;
    bChamp.priorite=priorite;
    mChampsListe.insert(j,bChamp);


    emit dataChanged();
    connect(valeurChamp,SIGNAL(dataChanged()),this,SIGNAL(dataChanged()));
}

int Structure::supprimerChamp(const int index)
{
    mChampsListe.removeAt(index);
    QPair<QString,Champ*> p=(*this)[index];
    int nb=mChamps.remove(p.first,p.second);
    emit dataChanged();
    return nb;
}

const Champ* Structure::operator[](const QString s) const
{
    return mChamps.value(s,NULL);
}

void Structure::vider()
{
    mChamps.clear();
    mChampsListe.clear();
}

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

QVariant Structure::image() const
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
    QList<BChamp> nouveau;
    int p=0;
    for(int i=0;i<mChampsListe.size();i++)
    {
        if(mChampsListe[i].nom!=s) nouveau<<mChampsListe[i];
        else p=mChampsListe[i].priorite;
    }
    mChampsListe=nouveau;

    mChamps.remove(s);

    ajouterChamp(s,c,p);
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
    mChampsListe=v.value<Structure*>()->mChampsListe;
    emit dataChanged();
    return true;
}

const QPair<QString,Champ*> Structure::operator[](const int n) const
{
    BChamp b=mChampsListe[n];
    return qMakePair(b.nom,b.valeur);
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
            ajouterChamp(l2[0],t,0);
        }
    }
    emit dataChanged();
    return true;
}
