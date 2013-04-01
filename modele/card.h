#ifndef CARD_H
#define CARD_H

#include "champ.h"

class Contact;
class Contacts;

/**
 * @brief La classe Card représente un champ contenant un contact (une personne ou une organisation)
 */
class Card : public Champ
{
    Q_OBJECT
public:

    Card(bool appartientAUnePersonne, QString nom="", QObject * parent=0);


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
    bool fromString(const QString nom);

    static Contacts * mContacts;

    QVariant image();

private:

    /**
     * @brief mContact est le contact reprsenté par le champ Card
     */
    Contact * mContact;
    bool mAppartientAUnePersonne;

};

#endif // CARD_H
