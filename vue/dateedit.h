/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef DATEEDIT_H
#define DATEEDIT_H

#include <QDateTimeEdit>

/**
 * @brief La classe DateEdit est un widget qui permet d'éditer une date
 */
class DateEdit : public QDateTimeEdit
{
    Q_OBJECT
    Q_PROPERTY(QDateTime enum READ dateTime WRITE setDateTime USER true)
public:
    /**
     * @brief Le constructeur par défaut
     */
    explicit DateEdit(QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // DATEEDIT_H
