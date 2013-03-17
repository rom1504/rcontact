#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>
#include "champ.h"
#include <QMultiMap>
#include <QString>
#include <QPair>

/**
 * @brief La classe Contact représente un contact enregistré, c'est à dire un multimap de champs.
 */
class Contact : public QObject
{
    Q_OBJECT
public:
    explicit Contact(QObject *parent = 0);
    Contact(const Contact & c,QObject *parent=0);
    ~Contact();

    /**
     * @brief ajouterChamp ajoute le champs libelé nomChamp avec la valeur valeurChamp
     * @param nomChamp Le nom du champ à ajouter (ex : "nom", "téléphone", ...)
     * @param valeurChamp La valeur du champ à ajouter
     */
    void ajouterChamp(const QString & nomChamp,Champ * valeurChamp);

    /**
     * @brief supprimerChamp supprime le champ libelé nomChamp qui a la valeur valeurChamp
     * @param nomChamp Le nom du champ à supprimer
     * @param valeurChamp La valeur du champ à supprimer
     * @return le nombre de valeurs supprimées
     */
    int supprimerChamp(const QString & nomChamp, Champ * valeurChamp);

    /**
     * @brief nombreValeurs
     * @return le nombre de valeur totales
     */
    int nombreValeurs() const;

    /**
     * @brief nom
     * @return Le nom du contact
     */
    QString nom() const;

    /**
     * @brief opérateur de comparaison
     */
    bool operator==(const Contact & c) const; // problème : ne sera pas utilisé dans le QMultiMap car ce sont des pointeurs qui sont stockés... : à vérifier...

    /**
     * @brief opérateur d'accès
     */
    const QPair<QString,Champ*> operator[](const int n) const;


signals:
    /**
     * @brief dataChanged est le signal déclenché lorsqu'une donnée est modifiée
     * @param debut
     * @param fin
     */
    void dataChanged(int debut,int fin);

private:
    /**
     * @brief mChamps est un multimap associant des libelés de champs (les QString) à des valeurs (les *Champ)
     */
    QMultiMap<QString,Champ*> mChamps;


};

#endif // CONTACT_H
