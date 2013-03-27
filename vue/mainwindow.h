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

private slots:

    void on_actionCharger_triggered();

    void on_actionTrier_triggered();

signals:
    void contactActive(const int index);
    void contactEdite(const int index);
    
private:
    Ui::MainWindow *ui;
    ModeleListeContacts * mModelListeContacts;
};

#endif // MAINWINDOW_H
