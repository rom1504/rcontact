#include "loc.h"
#include <QStringList>

Loc::Loc(const QString s)
{
    if(!fromString(s))
    {
        mLatitude=0;
        mLongitude=0;
    }
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
    mLatitude=l[0].toDouble();
    mLongitude=l[1].toDouble();
    return mLatitude!=0 && mLongitude!=0;
}

Loc::~Loc()
{

}
