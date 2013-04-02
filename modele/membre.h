/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef MEMBRE_H
#define MEMBRE_H
#include "structure.h"

/**
 * @brief The Membre class
 */
class Membre : public Structure
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur par défaut
     */
    explicit Membre(QObject *parent = 0);

    /**
     * @brief toVCard convertis l'objet en format vCard
     * @return Une QString contenant la conversion
     */
    QString toVCard() const;
    
signals:
    
public slots:
    
};

#endif // MEMBRE_H
