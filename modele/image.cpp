#include "image.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QUrl>
#include <QDebug>
#include <QNetworkReply>
#include <QNetworkProxy>

Image::Image(QObject *parent) :
    Structure(parent)
{
    connect(this,SIGNAL(dataChanged()),this,SLOT(chargerImage()));
}

QString Image::toString() const
{
    return "";
}

QVariant Image::image()
{
    if(mImage.isNull()) return QVariant();
    else return mImage;
}

// QUrl...
void Image::chargerImage()
{
    QString urls;
    if((urls=avoirChamp("url"))!="")
    {
        QNetworkAccessManager * m_netwManager;
        m_netwManager = new QNetworkAccessManager(this);
        m_netwManager->setProxy(QNetworkProxy(QNetworkProxy::DefaultProxy));
        connect(m_netwManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_netwManagerFinished(QNetworkReply*)));

        QUrl url(urls);
        QNetworkRequest request(url);
        //  QSslSocket::setProtocol(QSsl::SslV3);
        m_netwManager->get(request);
    }
}

QString Image::toVCard() const
{
    return avoirChamp("url");
}


void Image::slot_netwManagerFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
        return;
    }

    QByteArray jpegData = reply->readAll();
    mImage.loadFromData(jpegData);
    mImage=mImage.scaledToWidth(100);
    disconnect(this,SIGNAL(dataChanged()),this,SLOT(chargerImage()));
    emit dataChanged();
    connect(this,SIGNAL(dataChanged()),this,SLOT(chargerImage()));
}

