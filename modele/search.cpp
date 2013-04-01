#include "search.h"

Search::Search(QString nom, bool c, bool personne, bool organisme) : mNom(nom),mCase(c),mPersonne(personne),mOrganisme(organisme)
{
}

bool Search::operator ()(Contact * c) const
{
    return c->nom().contains(mNom,mCase ? Qt::CaseSensitive : Qt::CaseInsensitive)
            && (mOrganisme || QString(c->metaObject()->className())!="Organisme") &&
            (mPersonne || QString(c->metaObject()->className())!="Personne");
}
