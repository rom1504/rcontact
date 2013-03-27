#include "search.h"

Search::Search(QString nom,bool c) : mNom(nom),mCase(c)
{
}

bool Search::operator ()(Contact * c) const
{
    return c->nom().contains(mNom,mCase ? Qt::CaseSensitive : Qt::CaseInsensitive);
}
