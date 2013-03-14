#ifndef CHAMP_H
#define CHAMP_H

#include <QString>

class Champ
{
public:
    bool operator==(const Champ &) const;
    virtual QString toString() const;
    virtual ~Champ();
};

#endif // CHAMP_H
