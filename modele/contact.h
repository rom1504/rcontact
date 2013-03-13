#ifndef CONTACT_H
#define CONTACT_H

#include "champ.h"
#include <QMultiMap>

class Contact
{
public:
    Contact();
    void ajouterChamp(const QString & nomChamp,const Champ & valeurChamp);
    void supprimerChamp(const QString & nomChamp);

    bool operator==(const Contact & c) const;

private:
    QMultiMap<QString,Champ> mChamps;
};

#endif // CONTACT_H
