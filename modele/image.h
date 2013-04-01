#ifndef IMAGE_H
#define IMAGE_H

#include "structure.h"
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QPixmap>

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