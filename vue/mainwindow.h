#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setModeleListeContacts ( QAbstractItemModel * model );
    void setModeleAfficherContact ( QAbstractItemModel * model );
    void setModeleEditerContact ( QAbstractItemModel * model );

private slots:

    void on_actionCharger_triggered();

signals:
    void contactActive(const int index);
    void contactEdite(const int index);
    void chargerContacts(const QString nomFichier);
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
