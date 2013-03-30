#ifndef IMAGE_H
#define IMAGE_H

#include "structure.h"
#include <QtNetwork/QNetworkReply>
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

private slots:
    void slot_netwManagerFinished(QNetworkReply *reply);
    void chargerImage();

private:
    QPixmap mImage;
    
};

#endif // IMAGE_H
