#ifndef CHAMP_H
#define CHAMP_H

#include <QString>

class Champ
{
public:
    virtual bool operator==(const Champ &) const = 0;
    virtual QString toString() const = 0;
    virtual ~Champ() = 0;
};

#endif // CHAMP_H
