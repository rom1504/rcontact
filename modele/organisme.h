#ifndef ORGANISME_H
#define ORGANISME_H

#include "contact.h"

class Organisme : public Contact
{
public:
    Organisme();

    /**
     * @brief creerOrganisme créer un contact avec des champs caractéristiques d'un personne morale
     * @return un pointeur vers le contact créé
     */
    static Contact* creerDefaut();

    void creerChamp(const QString& nom, const QString& type);
};

#endif // ORGANISME_H
