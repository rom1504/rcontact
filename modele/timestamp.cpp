#include "timestamp.h"
#include <QDateTime>

Timestamp::Timestamp(const QString s)
{
     if(!fromString(s)) mT=0;
}

bool Timestamp::operator==(const Timestamp & c) const
{
    return mT==c.mT;
}

QString Timestamp::toString() const
{
    return QString::number(mT);
}

bool Timestamp::fromString(const QString s)
{
    mT=s.toUInt();
    return true;
}

Timestamp::~Timestamp()
{

}

QVariant Timestamp::toVariant() const
{
    return QDateTime::fromTime_t(mT);
}

bool Timestamp::fromVariant(const QVariant v)
{
    mT=v.toDateTime().toTime_t();
    return true;
}
