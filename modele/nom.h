#ifndef NOM_H
#define NOM_H

#include "structureoutexte.h"

class Nom : public StructureOuTexte
{
    Q_OBJECT
public:
    explicit Nom(QObject *parent = 0);

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

    QString toVCard() const;
    
signals:
    
public slots:

private:
    
};

#endif // NOM_H