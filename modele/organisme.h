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

    static Champ* gnom(const QString nom,const QString raisonSociale);
    static Champ* logo(const QString type,const QString url);
    static Champ* membre(const QString fonction,Card * card=new Card());

    void creerChamp(const QString& nomChamp, const QString& type);
};

#endif // ORGANISME_H
