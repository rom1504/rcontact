#include "champ.h"
#include <QTextDocument>

Champ::~Champ() {}

Champ::Champ(QObject * parent) : QObject(parent)
{

}

bool Champ::operator==(const Champ &) const
{
    return false;
}

QVariant Champ::toVariant()
{
    return toString();
}

bool Champ::fromVariant(const QVariant v)
{
    return fromString(v.toString());
}

QVariant Champ::image()
{
    return QVariant();
}

QString Champ::toVCard() const
{
    return toString();
}

void Champ::essayerEncore()
{

}

QString Champ::toXML() const
{
    return Qt::escape(toString());
}
