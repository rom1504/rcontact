/**
  * @author Romain BEAUMOUNT
  */

#ifndef GRANDTEXTEEDIT_H
#define GRANDTEXTEEDIT_H

#include <QTextEdit>
#include "../modele/grandtexte.h"

/**
 * @brief La classe GrandTexteEdit permet d'éditer un champ GrandTexte
 */
class GrandTexteEdit : public QTextEdit
{
    Q_OBJECT
    Q_PROPERTY(GrandTexte* grandTexte READ grandTexte WRITE setGrandTexte USER true)

public:
    explicit GrandTexteEdit(QWidget *parent = 0);

    /**
     * @brief grandTexte renvoie l'objet GrandTexte associé
     * @return L'objet GrandTexte associé
     */
    GrandTexte * grandTexte() const;
    /**
     * @brief setGrandTexte modifie l'objet GrandTexte
     * @param l'objet GrandTexte
     */
    void setGrandTexte(GrandTexte *g);
    
signals:
    
public slots:
    
};

#endif // GRANDTEXTEEDIT_H
