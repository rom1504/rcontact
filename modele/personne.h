#ifndef PERSONNE_H
#define PERSONNE_H

#include "contact.h"

class Personne : public Contact
{
    Q_OBJECT
public:
    Personne(QObject * parent=0);

    /**
     * @brief creerPersonne créer un contact avec des champs caractéristiques d'un personne physique
     * @return un pointeur vers le contact créé
     */
    static Contact* creerDefaut();

    static Champ* gnom(const QString nom="Nom",const QString prenom="Prénom",const QString prefixe="",const QString surnom="");
    static Champ* sexe(const QString sexe="homme");
    static Champ* photo(const QString url="",const QString type="JPEG");
    static Champ* organisation(Card *card=new Card());

    void creerChamp(const QString& nomChamp, const QString& type);
};

#endif // PERSONNE_H
