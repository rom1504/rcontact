/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef CHAMP_H
#define CHAMP_H

#include <QString>
#include <QVariant>
#include <QObject>

/**
 * @brief La classe Champ est la classe abstraite mère de toutes les classes symbolisant des champs de formulaire
 */
class Champ : public QObject
{
    Q_OBJECT
public:

    /**
     * @brief Champ constructeur par défaut
     * @param parent fourni le parent ou QObject
     */

    Champ(QObject * parent=0);

    /**
     * @brief toString convertit l'objet en format lisible
     * @return une QString contenant un format lisible du champ
     */
    virtual QString toString() const = 0;
    /**
     * @brief fromString convertit un QString en Champ
     * Elle n'est pas implémentée pour toutes les filles.
     * @return true si la conversion a réussi, false sinon
     */
    virtual bool fromString(const QString)= 0;

    /**
     * @brief toVariant convertit l'objet en QVariant
     * @return un QVariant décrivant exactement l'objet
     */
    virtual QVariant toVariant();

    /**
     * @brief fromVariant un QVariant en Champ
     * @param v le QVariant a convertir
     * @return true si la conversion a réussi, false sinon
     */
    virtual bool fromVariant(const QVariant v);

    /**
     * @brief image fourni une image à afficher
     * @return sous la forme d'un QVariant (QPixmap ou QIcon ou QImage)
     */

    virtual QVariant image();

    /**
     * @brief toVCard fait l'export en vCard
     * @return une QString qui contient le vCard
     */

    virtual QString toVCard() const;

    /**
     * @brief toXML fait l'export en XML
     * @return une QString qui contient le XML
     */
    virtual QString toXML() const;

    /**
     * @brief essayerEncore méthode à appeler si quelque chose doit être réésayé (utilisé en particulier dans Card)
     */

    virtual void essayerEncore();

    /**
     * @brief ~Champ destructeur
     */

    virtual ~Champ();

signals:
    /**
     * @brief dataChanged émis quand des données changent
     */
    void dataChanged();
};

#endif // CHAMP_H
