#rcontact
Gestionnaire de contacts

[![Build Status](https://travis-ci.org/rom1504/rcontact.png?branch=master)](https://travis-ci.org/rom1504/rcontact)

Organisation en Modèle, vue, controleur.

Pour lier la vue au modèle on utilise des modèles Qt : 
des classes qui héritent de QAbstractItemModel ( ou de qabstractlistmodel par exemple)
, voir http://qt-project.org/doc/qt-4.8/model-view-programming.html en particulier le commentaire tout à la fin , 
il faut voir les modèles Qt comme des adapteurs entre le "vrai" modèle qui contient les données et la vue.

Le lien est fait dans le controleur.

##Modele
###Contacts
Stocke les contacts et fait les opérations sur ceux-ci

####Contact
Stocke les valeurs des champs du contact et permet de récupéré certaine information à partir de ces valeurs
(le nom par exemple)

#####Champ
Classe abstraite qu'il faut hériter pour définir les types de champs

######Texte
Simple champ pour stocker du texte

######Card
Carte de contact : fait un lien avec un contact

######Enum
Prend un nombre fini de valeur possible

######Loc
Stocke une latitude et une longitude

######Structure
Stocke des champs chacun associé à une clé : représenté comme une MultiMap<QString,Champ*>

######Timestamp
Stocke un time_t

######Url
Stocke une url (hérite de Texte)


###ModeleListeContacts
Ce modèle Qt fait le lien entre Contacts et la QListView présente dans ListeContacts

###ModeleAfficherContact
Fait le lien entre Contact et la QTableView présente dans AfficherContact

###ModeleAfficherStructure
Fait le lien entre Structure et la QTableView présente dans StructureEdit

##Vue
###AfficherContact

###EditerContact

###AjouterContact

###EnumEdit

###LocEdit

###StructureEdit

###ListeContacts
Afficher les contacts

###MainWindow
Affiche ListeContacts, EditerContact et AfficherContact ainsi que le menu


##Controleur
###Controleur
Contient la vue et les modèles et fait le lien entre eux via des signaux et des setModel.

