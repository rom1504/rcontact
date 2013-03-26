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

    static Champ* gnom(const QString prefixe,const QString nom,const QString prenom,const QString surnom);
    static Champ* sexe(const QString sexe);
    static Champ* photo(const QString type,const QString url);
    static Champ* organisation(Card *card=new Card());

    void creerChamp(const QString& nomChamp, const QString& type);
};

#endif // PERSONNE_H
