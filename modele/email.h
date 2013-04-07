/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef EMAIL_H
#define EMAIL_H

#include "structureoutexte.h"

/**
 * @brief La classe Email représente un champ où l'utilisateur doit inscrire une adresse email
 */
class Email : public StructureOuTexte
{
    Q_OBJECT
public:

    /**
     * @brief Constructeur par défaut
     */
    explicit Email(QObject *parent = 0);
    explicit Email(const QString nom,const QString domaine,const QString extension);

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
