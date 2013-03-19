#include "timestamp.h"

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
