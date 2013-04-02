/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef ENUMEDIT_H
#define ENUMEDIT_H

#include <QComboBox>
#include "../modele/enum.h"

/**
 * @brief La class EnumEdit est le widget affichant les choix multiple d'un champ à énumération
 */
class EnumEdit : public QComboBox
{
    Q_OBJECT
public:
    /**
     * @brief EnumEdit Le constructeur par défaut
     */
    explicit EnumEdit(QWidget *parent = 0);

    Q_PROPERTY(Enum* enum READ getEnum WRITE setEnum USER true)

    /**
     * @brief getEnum renvoie la valeur de la sélection de l'énumération
     * @return La valeur de la sélection
     */
    Enum * getEnum() const;

    /**
     * @brief setEnum initialise l'énumération
     * @param c L'énumération à afficher
     */
    void setEnum(Enum *c);

    
public slots:

private:
    /**
     * @brief mEnum est l'index de la valeur dans l'énumération courante
     */
    int mEnum;


    
};

#endif // ENUMEDIT_H
