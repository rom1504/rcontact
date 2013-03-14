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
    bool b = false; // Mis à true si on trouve une correspondance
    QMultiMap<QString,Champ>::const_iterator it1 = mChamps.begin();
    while (it1 != mChamps.end() && !b)
    {
        QMultiMap<QString,Champ>::const_iterator it2 = c.mChamps.begin();
        while (it2 != c.mChamps.end() && !b)
        {
            // Comparaison des clés et des valeurs.
            b = (it1.key() == it2.key()) && (it1.value() == it2.value());
            it2++;
        }
        it1++;
    }
    return b;
}
