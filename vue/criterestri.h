#ifndef CRITERESTRI_H
#define CRITERESTRI_H

#include <QDialog>
#include "../modele/comp.h"

namespace Ui {
class CriteresTri;
}

/**
 * @brief La classe CriteresTri est la boîte de dialogue qui s'ouvre quand l'utilisateur clique sur le bouton pour trier la liste de contacts
 */
class CriteresTri : public QDialog
{
    Q_OBJECT
    
public:
    /**
     * @brief CriteresTri Le constructeur par défaut
     */
    explicit CriteresTri(QWidget *parent = 0);
    virtual ~CriteresTri();

    /**
     * @brief get ouvre la boîte de dialogue, attend que l'utilisateur confirme et renvoie les données qui en résulte
     * @return Les données entrée par l'utilisateur dans la boîte de dialogue
     */
    static Comp * get();
    
private:
    /**
     * @brief ui Un pointeur vers la user interface
     */
    Ui::CriteresTri *ui;
};

#endif // CRITERESTRI_H
