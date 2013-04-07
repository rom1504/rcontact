#ifndef GRANDTEXTE_H
#define GRANDTEXTE_H

#include "texte.h"

class GrandTexte : public Texte
{
    Q_OBJECT
public:
    /**
     * @brief Le constructeur par défaut
     * @param s La valeur par défaut (utilise fromString pour convertir la QString en le type approprié)
     */
    explicit GrandTexte(const QString value="",QObject * parent=0);

    /**
     * @brief toVariant convertit le champ en QVariant
     * @return Un QVariant représentant le champ
     */
    QVariant toVariant();

    /**
     * @brief fromVariant importe un champ depuis un QVariant
     * @param v Le QVariant à convertir en champ
     * @return true si la conversion a réussi
     */
    virtual bool fromVariant(const QVariant v);
    
signals:
    
public slots:
    
};

Q_DECLARE_METATYPE (GrandTexte*)

#endif // GRANDTEXTE_H
