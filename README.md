Ce programme à pour fonction de retourner des informations sur une adresse ip saisie par l'utilisateur qui sont :
-la classe de cette adresse
-le type de l'adrresse
-son réseau
-ses adresses hôtes

Pour ce faire, ce programme est composé de 5 fonctions qui sont :
-vérifierLeFormat : fonction qui enregistre l'adresse ip saisie si elle est valide et qui extrait les informations nécéssaire pour la suite (valeur de l'adresse et masque).
-viderBuffer : fonction qui est utiliser pour vider la mémoire au niveau de la saisie de l'ip si celle-ci n'est pas valide.
-conversion : fonction qui va convertir l'adresse ip d'une forme décimal à binaire.
-decoderIp : fonction qui va chercher à quel classe appartient l'ip saisie et son type avec les valeurs décimal de l'adresse IP.
-calculerReseauHote : fonction qui va trouver l'adresse du réseau et la plage d'hôtes possible avec la valeur binaire de l'adresse IP et son masque.

Dans la classe main figure seulement les appels des fonctions vériferLeFormat, conversion, decoderIp et calculerReseauHote avec en paramètre un tableau pour les valeurs décimal de l'Ip et un tableau pour les valeurs binaire de l'Ip.
