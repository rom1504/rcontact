#ifndef CONTACTS_H
#define CONTACTS_H

#include <QObject>
#include <QStringListModel>
#include "contact.h"
#include "comp.h"
#include "search.h"

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

    /**
     * @brief ajouterContact ajoute un contact avec des valeurs par défaut
     */
    Contact * ajouterContact();

    /**
     * @brief supprimerContact supprime un contact dans la liste
     * @param n L'index du contact à supprimer
     */
    void supprimerContact(const int n);

    /**
     * @brief nombre renvoie le nombre de contacts dans l'anuaire
     * @return la taille de l'anuaire
     */
    int nombre() const;

    /**
     * @brief charger charge un contact à partir d'un fichier au format vCard
     * @param nomFichier Le nom du fichier contenant les informations de la liste de contacts à charger
     */
    void charger(QString nomFichier);



    void changerTri(Comp * comp);

    Contacts * rechercher(Search * search) const;

    /**
     * @brief L'opérateur d'accès
     */
    Contact * operator[](const int n) const;

public slots:
    /**
     * @brief trier Trie les contacts de la liste, selon ordre et critère
     */
    void trier();

    /**
     * @brief enregistrer sauvegarde un contact au format vCard dans un fichier
     * @param nomFichier Le nom du fichier dans lequel on souhaite sauvegarder la liste de contacts
     */
    void enregistrer(QString nomFichier) const;


private:
    /**
     * @brief mContacts est la liste des contacts dans l'anuaire
     */
    QList<Contact*> mContacts;

    Comp * mComp;

signals:
    /**
     * @brief dataChanged est le signal émis lorsque des modifications sont faites dans la liste
     * @note Tous les éléments entre debut et fin ne sont pas forcément modifiés.
     */
    void dataChanged();

public slots:

};

#endif // CONTACTS_H
