#include "timestamp.h"
#include <QDateTime>

Timestamp::Timestamp(const QString s, QObject *parent) : Champ(parent)
{
     if(!fromString(s)) mT=0;
}

QString Timestamp::toString() const
{
    return QDateTime::fromTime_t(mT).toString();
}

bool Timestamp::fromString(const QString s)
{
    mT=QDateTime::fromString(s,Qt::ISODate).toTime_t();
    //mT=s.toUInt();
    emit dataChanged();
    return true;
}


QVariant Timestamp::toVariant()
{
    return QDateTime::fromTime_t(mT);
}

bool Timestamp::fromVariant(const QVariant v)
{
    mT=v.toDateTime().toTime_t();
    emit dataChanged();
    return true;
}

QString Timestamp::toVCard() const
{
    return ":"+QDateTime::fromTime_t(mT).toString("yyyy-MM-dd");
}


QString Timestamp::toXML() const
{
    return QDateTime::fromTime_t(mT).toString("yyyy-MM-dd");
}
