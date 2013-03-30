#ifndef EMAIL_H
#define EMAIL_H

#include "structureoutexte.h"

class Email : public StructureOuTexte
{
    Q_OBJECT
public:
    explicit Email(QObject *parent = 0);

    /**
     * @brief toString convertit l'objet en format lisible
     * @return une QString contenant un format lisible du champ
     */
    QString toString() const;
    /**
     * @brief fromString convertit un QString en Structure
     * @param s La QString à convertir
     * @return true si la conversion a réussi, false sinon
     */
    bool fromString(const QString s);
    
signals:
    
public slots:
    
};

#endif // EMAIL_H
