#ifndef LISTECONTACTS_H
#define LISTECONTACTS_H

#include <QWidget>
#include <QAbstractItemModel>
#include "../modele/modelelistecontacts.h"

namespace Ui {
class ListeContacts;
}

/**
 * @brief La classe ListeContacts est la zone d'affichage de la liste des contacts
 */
class ListeContacts : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Le constructeur par défaut
     */
    explicit ListeContacts(QWidget *parent = 0);
    ~ListeContacts();

    /**
     * @brief setModel détermine le modèle à aficher
     * @param model Le modèle à afficher
     */
    void setModel ( ModeleListeContacts * model );

    /**
     * @brief indexContactCourant renvoie l'index du contact sélectionné
     * @return L'index du contact sélectionné
     */
    int indexContactCourant();

    /**
     * @brief chargerContacts Charge les contacts à partir d'un fichier
     * @param nomFichier Le nom du fichier à charger
     */
    void chargerContacts(QString nomFichier);

signals:
    void contactActive(const int index);
    void contactEdite(const int index);

public slots:
    void supprimerContactCourant();
    void editerContactCourant();
    void afficherContactCourant();
    void creerContact();

private slots:
    void afficherContact(const QModelIndex & index);

private:
    Ui::ListeContacts *ui;
   ModeleListeContacts * mModel;
};

#endif // LISTECONTACTS_H
