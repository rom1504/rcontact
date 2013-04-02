/**
  * @author Romain BEAUMOUNT
  * @author Thomas LOURSEYRE
  */

#ifndef ORGANISME_H
#define ORGANISME_H

#include "contact.h"

/**
 * @brief La classe Organisme représente un contact avec le template d'un organisme
 */
class Organisme : public Contact
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur vide
     */
    Organisme(QObject * parent=0);


    /**
     * @brief image
     * @return Le logo de l'organisme
     */
    QVariant image() const;

    /**
     * @brief creerOrganisme créer un contact avec des champs caractéristiques d'un personne morale
     * @return un pointeur vers le contact créé
     */
    static Organisme *creerDefaut();

    /**
     * @brief gnom créé un champ sensé décrire un nom d'Organisme initialisé avec les valeurs passées en paramètre
     * @param nom Le paramètre "nom" du champ
     * @param raisonSociale Le paramètre "raison sociale" du champ
     * @return Un pointeur vers le champ créé
     */
    static Champ* gnom(const QString nom=tr("Nom"),const QString raisonSociale=tr("raison sociale"));

    /**
     * @brief logo créé un champ sensé décrire un logo d'Organisme initialisé avec les valeurs passées en paramètre
     * @param url Le paramètre "url" du champ
     * @param type Le paramètre "type" du champ
     * @return Un pointeur vers le champ créé
     */
    static Champ* logo(const QString url="",const QString type=tr("JPEG"));

    /**
     * @brief membre créé un champ sensé décrire un membre d'Organisme initialisé avec les valeurs passées en paramètre
     * @param fonction Le paramètre "fonction" du champ
     * @param card Le paramètre "card" du champ
     * @return Un pointeur vers le champ créé
     */
    static Champ* membre(const QString fonction="",QString card="");

    /**
     * @brief creerChamp créé et ajoute un champ
     * @param nomChamp le nom du champ à créer
     * @param type Le type du champ à créer
     */
    void creerChamp(const QString& nomChamp, const QString& type);
};

#endif // ORGANISME_H
