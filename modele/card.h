#ifndef CARD_H
#define CARD_H

#include "champ.h"
#include "contact.h"

class Card : public Champ
{
public:
    Card(const Contact * contact);
    bool operator==(const Card & c) const;
    QString toString() const;
    bool fromString(const QString s);
    ~Card();
private:
    const Contact * mContact;
};

#endif // CARD_H
