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
}


bool Contact::operator==(const Contact & c) const
{ // pas bon
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
    return mChamps.value("nom")->toString();
}

int Contact::nombreValeurs() const
{
    return mChamps.count();
}


const QPair<QString,Champ*> Contact::operator[](const int n) const
{
    return qMakePair((mChamps.keys())[n],(mChamps.values())[n]);
}

int Contact::supprimerChamp(const int index)
{
    QPair<QString,Champ*> p=(*this)[index];
    return supprimerChamp(p.first,p.second);
}

int Contact::supprimerChamp(const QString & nomChamp,Champ * valeurChamp)
{
    int nb=mChamps.remove(nomChamp,valeurChamp);// pas bon : que si même pointeur... : à faire en utilisant les iterateurs.
    //: en fait ça va : passer en privé ?
    return nb;
}
