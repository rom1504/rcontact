#include "contact.h"

Contact::Contact()
{

}

void Contact::ajouterChamp(const QString & nomChamp, const Champ & valeurChamp)
{
    mChamps.insert(nomChamp,valeurChamp);
}

void Contact::supprimerChamp(const QString & nomChamp)
{
    mChamps.remove(nomChamp);
}


bool Contact::operator==(const Contact & c) const
{
    return true;
}
