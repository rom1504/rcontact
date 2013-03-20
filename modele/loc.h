#ifndef LOC_H
#define LOC_H

#include "champ.h"

class Loc : public Champ
{
public:
    Loc(const QString s="");
    bool operator==(const Loc & c) const;
    QString toString() const;
    bool fromString(const QString s);
    ~Loc();
private:
    double mLatitude;
    double mLongitude;
};

#endif // LOC_H
