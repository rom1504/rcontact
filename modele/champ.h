#ifndef CHAMP_H
#define CHAMP_H

#include <QString>

/**
 * @brief La classe Champ est la classe abstraite mère de toutes les classes symbolisant des champs de formulaire
 */
class Champ
{
public:
    virtual bool operator==(const Champ & c) const = 0;
    virtual QString toString() const = 0;
    virtual void fromString(const QString s)= 0;
    virtual ~Champ() = 0;
};

#endif // CHAMP_H
