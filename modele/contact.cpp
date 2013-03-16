#include "contact.h"

Contact::Contact(QObject *parent) :
    QObject(parent)
{

}

Contact::~Contact()
{

}

Contact::Contact(const Contact & c,QObject *parent) : QObject(parent)
{
    mChamps=c.mChamps;
}

void Contact::ajouterChamp(const QString & nomChamp,Champ * valeurChamp)
{
    mChamps.insert(nomChamp,valeurChamp);
    emit dataChanged(0,nombreValeurs()-1); // on peut sans doute faire mieux ici
}


bool Contact::operator==(const Contact & c) const
{
    bool b = false; // Mis à true si on trouve une correspondance
    QMultiMap<QString,Champ*>::const_iterator it1 = mChamps.begin();
    while (it1 != mChamps.end() && !b)
    {
        QMultiMap<QString,Champ*>::const_iterator it2 = c.mChamps.begin();
        while (it2 != c.mChamps.end() && !b)
        {
            // Comparaison des clés et des valeurs.
            b = (it1.key() == it2.key()) && (*(it1.value()) == *(it2.value()));
            it2++;
        }
        it1++;
    }
    return b;
}


QString Contact::nom() const
{
    return "NOOOOOOM";
}

int Contact::nombreValeurs() const
{
    return mChamps.count();
}


const QPair<QString,Champ*> Contact::operator[](const int n) const
{
    return qMakePair((mChamps.keys())[n],(mChamps.values())[n]);
}
