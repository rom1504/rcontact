#ifndef AFFICHERCONTACT_H
#define AFFICHERCONTACT_H

#include <QWidget>
#include <QAbstractItemModel>

namespace Ui {
class AfficherContact;
}

/**
 * @brief La classe AfficherContact est la zone d'affichage d'un contact
 */
class AfficherContact : public QWidget
{
    Q_OBJECT
    
public:
    /**
     * @brief Le constructeur par défaut
     */
    explicit AfficherContact(QWidget *parent = 0);
    virtual ~AfficherContact();

    /**
     * @brief setModel détermine le modèle à aficher
     * @param model Le modèle à afficher
     */
    void setModel ( QAbstractItemModel * model );
    
private:
    /**
     * @brief ui Un pointeur vers la user interface
     */
    Ui::AfficherContact *ui;
};

#endif // AFFICHERCONTACT_H
