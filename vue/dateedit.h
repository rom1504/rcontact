#ifndef DATEEDIT_H
#define DATEEDIT_H

#include <QDateTimeEdit>

class DateEdit : public QDateTimeEdit
{
    Q_OBJECT
    Q_PROPERTY(QDateTime enum READ dateTime WRITE setDateTime USER true)
public:
    explicit DateEdit(QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // DATEEDIT_H
