#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QObject>
#include "vue/mainwindow.h"
#include "modele/contacts.h"

/**
 * @brief La classe Controleur permet de lier le modèle et la vue (en connectant les signaux et les slots)
 */
class Controleur : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Controleur est le constructeur de la classe
     * @param parent Le Qobject parent (à laisser null par défaut)
     */
    explicit Controleur(QObject *parent = 0);
    /**
     * @brief run lance le controleur
     */
    void run();

private:
    /**
     * @brief mVue contient la vue
     */
    MainWindow mVue;
    /**
     * @brief mContacts contient le modèle
     */
    Contacts mContacts;

private slots:
    /**
     * @brief afficherContact est le slot appelé quand on souhaite afficher un contact
     * @param index Le numéro d'index dans le modèle du contact à afficher
     */
    void afficherContact(int index);
    /**
     * @brief editerContact est le slot appelé quand on souhaite modifier un contact
     * @param index Le numéro d'index dans le modèle du contact à modifier
     */
    void editerContact(int index);

    /**
     * @brief chargerContacts est le le slot appelé quand on souhaite charger une liste de contacts depuis un format vCard
     * @param nomFichier le nom du fichier à importer
     */
    void chargerContacts(QString nomFichier);

    /**
     * @brief trierContacts trie les contacts de manière ascendante oou descendante selon le critère passé en paramètre
     * @param ordre L'ordre de tri (true : ascendant, false : descendant)
     * @param critereTri Le nom du champ servant de critère de comparaison pour le tri
     */
    void trierContacts(bool ordre,QString critereTri);

signals:

public slots:

};

#endif // CONTROLEUR_H
