#ifndef TEXTE_H
#define TEXTE_H

#include <QString>
#include "champ.h"

class Texte : public Champ
{
public:
    Texte(const QString value="");
    void setValue(const QString value);
    QString value() const;
    virtual bool operator==(const Texte & t) const;
    QString toString() const;
    bool fromString(const QString s);
    ~Texte();

protected:
    QString mValue;
};

#endif // TEXTE_H
