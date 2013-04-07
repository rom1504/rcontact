/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

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

    /**
     * @brief Constructeur
     * @param appartientAUnePersonne Un booléen qui permet de savoir si la Card représente une personne ou un organisme
     * @param nom Le nom
     */
    Card(bool appartientAUnePersonne, QString nom="", QObject * parent=0);

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

    /**
     * @brief mContacts contient un pointeur vers l'ensemble des contacts (nécessaire pour rechercher parmi les contact celui qui a ce nom
     */
    static Contacts * mContacts;

    /**
     * @brief image fourni une image à afficher
     * @return sous la forme d'un QVariant (QPixmap ou QIcon ou QImage)
     */
    QVariant image();

    /**
     * @brief essayerEncore permet de tenter de trouver le contact associé si on a pas réussi la première fois (nécessaire lors de l'import)
     */
    void essayerEncore();

private:

    /**
     * @brief mContact est le contact reprsenté par le champ Card
     */
    Contact * mContact;

    /**
     * @brief mAppartientAUnePersonne permet de savoir si la card appartient à une personne ou à un organisme
     */

    bool mAppartientAUnePersonne;

    /**
     * @brief mTempNom stocke le nom de recherche de la vcard au cas où on voudrait appeler essayerEncore()
     */

    QString mTempNom;

};

#endif // CARD_H
