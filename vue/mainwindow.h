/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemModel>
#include "../modele/modelelistecontacts.h"

namespace Ui {
class MainWindow;
}

/**
 * @brief La fenetre principale
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    /**
     * @brief Le constructeur par défaut
     */
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /**
     * @brief setModeleListeContacts est le setter du modèle représentant la liste de contacts
     * @param model Le nouveau modèle
     */
    void setModeleListeContacts ( ModeleListeContacts * model );
    /**
     * @brief setModeleAfficherContact est le setter du modèle permettant d'afficher un contact
     * @param model Le nouveau modèle
     */
    void setModeleAfficherContact ( QAbstractItemModel * model );
    /**
     * @brief setModeleEditerContact est le setter du modèle permettant d'éditer un contact
     * @param model Le nouveau modèle
     */
    void setModeleEditerContact ( QAbstractItemModel * model );
    /**
     * @brief cacherContact permet de cacher les layouts d'affichage et d'édition de contact
     */
    void cacherContact();

    /**
     * @brief charger permet de charger un fichier
     * @param fichier nom du fichier
     * @param type type du fichier
     */

    void charger(QString fichier,QString type);

private slots:

    /**
     * @brief on_actionCharger_triggered est le slot appelé lorsque l'on veut charger une liste de contacts
     */
    void on_actionCharger_triggered();

    /**
     * @brief on_actionTrier_triggered est le slot appelé lorsque l'on veut trier la liste de contacts
     */
    void on_actionTrier_triggered();

    /**
     * @brief on_actionRechercher_triggered est le slot appelé lorsque l'on veut effectuer une recherche dans la liste
     */
    void on_actionRechercher_triggered();

    /**
     * @brief on_actionFinir_la_recherche_triggered est le slot appelé lorsque l'on veut terminer la recherche dans la liste
     */
    void on_actionFinir_la_recherche_triggered();

    /**
     * @brief on_actionEnregistrer_triggered est le slot appelé lorsque l'on veut enregistrer une liste de contacts
     */
    void on_actionEnregistrer_triggered();

    void on_actionNouvelle_liste_triggered();

    void on_actionEnregistrer_sous_triggered();

    void on_actionDefinir_comme_fichier_par_defaut_triggered();

signals:
    /**
     * @brief contactActive est le signal déclenché lorsqu'on sélectionne un contact dans la liste
     * @param index L'index du contact sélectionné
     */
    void contactActive(const int index);
    /**
     * @brief contactEdite est le signal déclenché lorsqu'on lance l'édition d'un contact
     * @param index L'index du contact que l'on veut éditer
     */
    void contactEdite(const int index);
    /**
     * @brief rechercherContacts est le signal déclenché lorsqu'on lance une rechercje sur les contacts
     * @param search Le foncteur servant à vérifier le un contact correspond à celui/ceux recherché(s)
     */
    void rechercherContacts(Search * search);
    /**
     * @brief finirLaRecherche est le signal déclenché lorsqu'on termine la recherche
     */
    void finirLaRecherche();
    /**
     * @brief enregistrerContacts est le signal déclenché lorsqu'on enregistre un contact
     * @param nomFichier Le nom du fichier dans lequel on enregistre
     * @param type Le format d'enregistrement (vCard ou XML)
     */
    void enregistrerContacts(QString nomFichier,QString type);
    
private:
    /**
     * @brief ui est la user interface
     */
    Ui::MainWindow *ui;
    /**
     * @brief mModelListeContacts est le modèle représentant la liste de contacts
     */
    ModeleListeContacts * mModelListeContacts;
    /**
     * @brief mFichierOuvert est la liste de contact ouverte
     */
    QString mFichierOuvert;

    /**
     * @brief mTypeFichierOuvert est le type du fichier ouvert
     */
    QString mTypeFichierOuvert;
};

#endif // MAINWINDOW_H
