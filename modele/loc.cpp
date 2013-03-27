#include "loc.h"
#include <QStringList>

Loc::Loc(const double latitude, const double longitude, QObject *parent)
    : Champ(parent),mLatitude(latitude),mLongitude(longitude)
{

}

Loc::Loc(const Loc & l,QObject * parent) : Champ(parent),mLatitude(l.mLatitude),mLongitude(l.mLongitude)
{

}


bool Loc::operator==(const Loc & c) const
{
    return mLatitude!=c.mLatitude && mLongitude!=mLongitude;
}

QString Loc::toString() const
{
    return QString::number(mLatitude)+","+QString::number(mLongitude);
}


bool Loc::fromString(const QString s)
{
    QString s2=s;
    QStringList l=s2.split(",");
    if(l.length()!=2) return false;
    if(!(0<=l[0].toDouble() && l[0].toDouble()<=90 && -180<=l[1].toDouble() && l[1].toDouble()<=180)) return false;
    mLatitude=l[0].toDouble();
    mLongitude=l[1].toDouble();
    emit dataChanged();
    return true;
}

double Loc::latitude() const
{
    return mLatitude;
}

double Loc::longitude() const
{
    return mLongitude;
}

QVariant Loc::toVariant()
{
    return QVariant::fromValue(this);
}

bool Loc::fromVariant(const QVariant v)
{
   Loc * w=v.value<Loc*>();
   double la=w->mLatitude;
   double lo=w->mLongitude;
   if(!(0<=la && la<=90 && -180<=lo && lo<=180)) return false;
   mLatitude=la;
   mLongitude=lo;
   emit dataChanged();
   return true;
}
