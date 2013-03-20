#ifndef TIMESTAMP_H
#define TIMESTAMP_H
#include <ctime>
#include "champ.h"

class Timestamp : public Champ
{
public:
    Timestamp(const QString s="");
    bool operator==(const Timestamp & c) const;
    QString toString() const;
    bool fromString(const QString s);
    ~Timestamp();
private:
    time_t mT;
};

#endif // TIMESTAMP_H
