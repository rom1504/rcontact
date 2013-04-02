/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef IMAGE_H
#define IMAGE_H

#include "structure.h"
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QPixmap>

/**
 * @brief La classe Image représente un champ représentant une image
 */
class Image : public Structure
{
    Q_OBJECT
public:
    explicit Image(QObject *parent = 0);

    /**
     * @brief toString convertit l'objet en format lisible
     * @return une QString contenant un format lisible du champ
     */
    QString toString() const;

    /**
     * @brief image est la conversion du champ en QVariant
     * @return Une QVariant représentant le champ
     */
    QVariant image();
    QString toVCard() const;

private slots:
    void slot_netwManagerFinished(QNetworkReply *reply);
    void chargerImage();

private:
    QPixmap mImage;
    QNetworkAccessManager * m_netwManager;
    
};

#endif // IMAGE_H
