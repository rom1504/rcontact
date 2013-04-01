#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemModel>
#include "../modele/modelelistecontacts.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setModeleListeContacts ( ModeleListeContacts * model );
    void setModeleAfficherContact ( QAbstractItemModel * model );
    void setModeleEditerContact ( QAbstractItemModel * model );
    void cacherContact();

private slots:

    void on_actionCharger_triggered();

    void on_actionTrier_triggered();

    void on_actionRechercher_triggered();

    void on_actionFinir_la_recherche_triggered();

    void on_actionEnregistrer_triggered();

signals:
    void contactActive(const int index);
    void contactEdite(const int index);
    void rechercherContacts(Search * search);
    void finirLaRecherche();
    void enregistrerContacts(QString nomFichier);
    
private:
    Ui::MainWindow *ui;
    ModeleListeContacts * mModelListeContacts;
};

#endif // MAINWINDOW_H
