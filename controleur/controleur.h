/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

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
    explicit Controleur(QString locale,QTranslator * translator,QObject *parent = 0);
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
     * @brief mContacts contient le modèle (peut être une partie du modèle en cas de recherche)
     */
    Contacts * mContacts;


    /**
     * @brief mContactsEntier contient le modèle entier
     */

    Contacts * mContactsEntier;

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
     * @brief rechercherContacts est le slot appelé quand on souhaite rechercher des contacts
     * @param search foncteur permettant de faire la recherche
     */

    void rechercherContacts(Search * search);

    /**
     * @brief finirLaRecherche permet de revenir au modèle complet
     */

    void finirLaRecherche();

signals:

public slots:

};

#endif // CONTROLEUR_H
