#ifndef SEARCH_H
#define SEARCH_H

#include <functional>
#include "contact.h"


class Search : public std::unary_function<Contact*,bool>
{
public:
    Search(QString nom,bool c,bool personne,bool organisme);
    bool operator()(Contact * c) const;
private:
    QString mNom;
    bool mCase;
    bool mPersonne;
    bool mOrganisme;
};
#endif // SEARCH_H
