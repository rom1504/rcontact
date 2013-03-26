#ifndef PERSONNE_H
#define PERSONNE_H

#include "contact.h"

class Personne : public Contact
{
public:
    Personne();

    /**
     * @brief creerPersonne créer un contact avec des champs caractéristiques d'un personne physique
     * @return un pointeur vers le contact créé
     */
    static Contact* creerDefaut();

    void creerChamp(const QString& nom, const QString& type);
};

#endif // PERSONNE_H
