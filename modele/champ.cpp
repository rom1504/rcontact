#include "champ.h"


// Implémentation bidon pour ne pouvoir comparer les valeur Champ dans le multimap
bool Champ::operator ==(const Champ &) const
{
    return 0;
}

QString Champ::toString() const
{
    return "il ne faut pas afficher ça...";
}


Champ::~Champ()
{

}
