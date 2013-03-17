#ifndef STRUCTURE_H
#define STRUCTURE_H

#include "champ.h"
#include <QMultiMap>

class Structure : public Champ
{
public:
    Structure();
    void ajouterChamp(const QString & nomChamp,Champ * valeurChamp);
    int supprimerChamp(const QString & nomChamp, Champ *valeurChamp);
    bool operator==(const Structure & c) const;
    bool operator==(const Champ & t) const;
    virtual QString toString() const;
    virtual ~Structure();

private:
    QMultiMap<QString,Champ*> mChamps;
};

#endif // STRUCTURE_H
