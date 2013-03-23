#include "loc.h"
#include <QStringList>

Loc::Loc(const double latitude, const double longitude)
    : mLatitude(latitude),mLongitude(longitude)
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

Loc::~Loc()
{

}

QVariant Loc::toVariant() const
{
    return QVariant::fromValue(*this);
}

bool Loc::fromVariant(const QVariant v)
{
   if(!(0<=v.value<Loc>().mLatitude && v.value<Loc>().mLatitude<=90 && -180<=v.value<Loc>().mLongitude && v.value<Loc>().mLongitude<=180)) return false;
   mLatitude=v.value<Loc>().mLatitude;
   mLongitude=v.value<Loc>().mLongitude;
   return true;
}
