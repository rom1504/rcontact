#ProjetLOA
Gestionnaire de contacts

Organisation en vue/modèle

Pour lier la vue au modèle on utilise des modèles Qt : 
des classes qui héritent de QAbstractItemModel ( ou de qabstractlistmodel par exemple)
, voir http://qt-project.org/doc/qt-4.8/model-view-programming.html en particulier le commentaire tout à la fin , 
il faut voir les modèles Qt comme des adapteurs entre le "vrai" modèle qui contient les données et la vue.

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

###ModeleListeContacts
Ce modèle Qt fait le lien entre Contacts et la QListView présente dans ListeContacts

###ModeleAfficherContact
Fait le lien entre Contact et la QTableView présente dans AfficherContact


##Vue
###AfficherContact

###EditerContact

###ListeContacts
Afficher les contacts

###MainWindow
Affiche ListeContacts, EditerContact et AfficherContact ainsi que le menu


##Controleur
###Controleur
Contient la vue et les modèles et fait le lien entre eux via des signaux et des setModel.

