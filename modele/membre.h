/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef MEMBRE_H
#define MEMBRE_H
#include "structure.h"

class Membre : public Structure
{
    Q_OBJECT
public:
    explicit Membre(QObject *parent = 0);

    QString toVCard() const;
    
signals:
    
public slots:
    
};

#endif // MEMBRE_H
