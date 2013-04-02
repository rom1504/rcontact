/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

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
    /**
     * @brief contactActive est le signal déclenché lors de la sélection d'un contact
     * @param index L'index du contact en subrillance
     */
    void contactActive(const int index);
    /**
     * @brief contactEdite est le signal déclanché lors de l'édition d'un contact
     * @param index L'index du contact édité
     */
    void contactEdite(const int index);

public slots:
    /**
     * @brief supprimerContactCourant est le slot appelé lors de la suppression du contact en subrillance
     */
    void supprimerContactCourant();
    /**
     * @brief editerContactCourant est le slot appelé lors de l'édition du contact en subrillance
     */
    void editerContactCourant();
    /**
     * @brief afficherContactCourant est le slot appelé lors de l'affichage du contact en subrillance
     */
    void afficherContactCourant();
    /**
     * @brief creerPersonne est le slot appelé lorsqu'on créé une personne
     */
    void creerPersonne();
    /**
     * @brief creerOrganisme est le slot appelé lorsqu'on créé un organisme
     */
    void creerOrganisme();
    /**
     * @brief creerOrganisme est le slot appelé lorsqu'on créé un contact
     * @param contact Le contact à créer
     */
    void creerContact(Contact * contact);

private slots:

    /**
     * @brief creerOrganisme est le slot appelé lorsqu'on affiche un contact
     * @param index L'index du contact à afficher
     */
    void afficherContact(const QModelIndex & index);

private:
    /**
     * @brief ui est la user interface
     */
    Ui::ListeContacts *ui;
    /**
    * @brief mModel le modèle de la liste de contact
    */
   ModeleListeContacts * mModel;
};

#endif // LISTECONTACTS_H
