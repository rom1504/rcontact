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
    QString toString() const;
    bool fromString(const QString s);
    ~Structure();

private:
    QMultiMap<QString,Champ*> mChamps;
};

#endif // STRUCTURE_H
