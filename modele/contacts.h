#ifndef CONTACTS_H
#define CONTACTS_H

#include <QObject>
#include <QStringListModel>
#include "contact.h"

/**
 * @brief La classe Contacts représente un anuaire de contacts
 */
class Contacts : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Le constructeur par défaut de la classe
     * @param parent Le QObject parent
     */
    explicit Contacts(QObject *parent = 0);
    /**
     * @brief ajouterContact ajoute un contact dans l'anuaire
     * @param contact Un poiteur vers le contact à ajouter
     */
    void ajouterContact(Contact * contact);

    void ajouterContact();
    /**
     * @brief supprimerContact supprime un contact dans la liste
     * @param n L'index du contact à supprimer
     */
    void supprimerContact(const int n);
    /**
     * @brief nombre renvoie le nombre de contacts dan l'anuaire
     * @return la taille de l'anuaire
     */
    int nombre() const;

    void charger(QString nomFichier);

    void enregistrer(QString nomFichier) const;

    void trier(bool ordre,QString critereTri);

    /**
     * @brief L'opérateur d'accès
     */
    Contact * operator[](const int n) const;

private:
    /**
     * @brief mContacts est la liste des contacts dans l'anuaire
     */
    QList<Contact*> mContacts;

signals:
    /**
     * @brief dataChanged est le signal émis lorsque des modifications sont faites dans la liste
     * @param debut L'index du premier élément modifié
     * @param fin L'index du dernier élément modifié
     * @note Tous les éléments entre debut et fin ne sont pas forcément modifiés.
     */
    void dataChanged(int debut,int fin);

public slots:

};

#endif // CONTACTS_H
