#ifndef STRUCTUREOUTEXTE_H
#define STRUCTUREOUTEXTE_H

#include "structure.h"

class StructureOuTexte : public Structure
{
    Q_OBJECT
public:
    explicit StructureOuTexte(QObject *parent = 0);

    QVariant toVariant();
    virtual bool fromVariant(const QVariant v);
    
signals:
    
public slots:
    
};

Q_DECLARE_METATYPE (StructureOuTexte*)

#endif // STRUCTUREOUTEXTE_H
