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
     * @param parent est le Qobject parent (à laisser null par défaut)
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
     * @param index est le numéro d'index dans le modèle du contact à afficher
     */
    void afficherContact(int index);
    /**
     * @brief editerContact est le slot appelé quand on souhaite modifier un contact
     * @param index est le numéro d'index dans le modèle du contact à modifier
     */
    void editerContact(int index);

signals:

public slots:

};

#endif // CONTROLEUR_H
