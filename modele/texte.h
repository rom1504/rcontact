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
    bool operator==(const Texte & t) const;

private:
    QString mValue;
};

#endif // TEXTE_H
