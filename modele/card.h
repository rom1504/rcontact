#ifndef CARD_H
#define CARD_H

#include "champ.h"

class Contact;

/**
 * @brief La classe Card représente un champ contenant un contact (une personne ou une organisation)
 */
class Card : public Champ
{
public:
    /**
     * @brief Le constructeur de classe prenant en argument le Contact à stocker.
     * @param contact Le contact à enregistrer
     */
    Card(const Contact * contact=NULL);
    /**
     * @brief L'opérateur d'égalité
     */
    bool operator==(const Card & c) const;
    /**
     * @brief toString affiche le contenu de la classe (i.e. le contact stocké)
     * @return une QString qui contient la description du contact stocké.
     */
    QString toString() const;
    /**
     * @brief fromString ne fait rien
     * @return false
     */
    bool fromString(const QString);
    ~Card();
private:
    /**
     * @brief mContact est le contact reprsenté par le champ Card
     */
    const Contact * mContact;
};

#endif // CARD_H
