/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef ADRESSE_H
#define ADRESSE_H

#include "structureoutexte.h"
#include "loc.h"

class Adresse : public StructureOuTexte
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur par défaut
     */
    explicit Adresse(QObject *parent = 0);


    explicit Adresse(const QString rue,const QString zipcode,const QString localite,const QString region,const QString pays,const QString type,Loc * geo,QObject *parent = 0);

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

    /**
     * @brief toVCard fait l'export en vCard
     * @return une QString qui contient le vCard
     */

    QString toVCard() const;

signals:
    
public slots:
    
};

#endif // ADRESSE_H
