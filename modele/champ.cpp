#include "champ.h"

Champ::~Champ() {}


bool Champ::operator==(const Champ &) const
{
    return false;
}

QVariant Champ::toVariant() const
{
    return toString();
}

bool Champ::fromVariant(const QVariant v)
{
    return fromString(v.toString());
}
