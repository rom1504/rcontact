#include "email.h"
#include <QStringList>
#include "texte.h"

Email::Email(QObject *parent) :
    StructureOuTexte(parent)
{
}


/**
 * @brief toString convertit l'objet en format lisible
 * @return une QString contenant un format lisible du champ
 */
QString Email::toString() const
{
    QString s=(avoirChamp(tr("nom"))+"@"+avoirChamp(tr("domaine"))+"."+avoirChamp(tr("extension"))).trimmed();
    return s=="." ? "" : s;
}

/**
 * @brief fromString convertit un QString en Structure
 * @param s La QString à convertir
 * @return true si la conversion a réussi, false sinon
 */
bool Email::fromString(const QString s)
{
    vider();
    // à améliorer ? (regex)
    QStringList l=s.split("@");
    QString nom="",domaine="",extension="";
    if(l.length()>=2)
    {
        nom=l.takeFirst();
        if(l.length()>=1)
        {
            QStringList l2=l.takeFirst().split(".");
            if(l2.length()>=2)
            {
                domaine=l2.takeFirst();
                extension=l2.join(".");
            }
        }
    }
    ajouterChamp(tr("nom"),new Texte(nom));
    ajouterChamp(tr("domaine"),new Texte(domaine));
    ajouterChamp(tr("extension"),new Texte(extension));
    return true;
}

