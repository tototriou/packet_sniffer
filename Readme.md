# Projet sniffeur de paquet

## Présentation du projet   

L'objectif de ce projet est de réaliser un sniffeur réseau sur toutes les couches réseaux. Les protocoles détéctés sont les suivants :  
- ethernet  
- IPv4, IPv6, ARP  
- UDP, TCP, ICMP(pas développée)  
- FTP, SMTP, DNS, BOOTP(DHCP), HTTP, POP3, IMAP, Telnet.

Différentes options de capture sont disponibles pour le sniffeur :
- *-i*  pour choisir l'interface réseau à écouter
- *-f*  pour choisir le filtre à appliquer
- *-h*  pour afficher l'aide
- *-o*  pour capturer hors ligne
- *-n*  pour choisir le nombre de trames à capturer
- *-v*  pour choisir la verbosité (obligatoire mais modifiabe à l'initialisation de la structure *options*)    
- *-p*  pour choisir le protocole à écouter (par défaut tous les protocoles) l'option n'a pas encore été implémentée mais les bases sont présentes dans le code (il suffit de rajouter un *if* aud début de chaque fichier).

L'affichage des trames se fait dans le terminal et les trames sont séparées par un trait horizontal. 


## structure du projet 

5 dossiers composent le pojet :   
- *bin*  pour l'executable.
- *include*  pour tous les *.h*.
- *obj*  pour les *.o*  .
- *src*  pour les *.c* .
- *exemples*  pour les fichiers de test en mode offline.

1 Makefile  
1 Readme

Pour chaque protocole il y a un fichier *.c* et un fichier *.h* dédié avec une description succinte des fonctions dans chaque *.h*, s'y reporter pour plus de détails. Dans chaque protocole, en fonction du niveau de verbositer, l'affichage sera différent. Pour réduire le temps de calcul, dans les niveaux de verbosité 1 et 2, je ne cherche pas à décoder l'ensemble de la trame mais uniquement les informations demandées. Seul en niveau de verbosité 3 le décriptage total du paquet est réalisé.


## Commandes

Pour lancer le projet il suffit de taper les lignes suivantes :
````
make clean 
make
sudo ./bin/exe {options}
````
L'option *-h* permet d'avoir le détail des usages pour utiliser le projet. 

## Avancement du projet

Le projet tel qu'il a été demandé dans le sujet est terminé. Il reste quelques  améliorations à apporter au niveau de l'affichage et du décriptage de certains protocoles(DNS par exemple en verbosité 3). Des options ont été ajoutées pour faciliter l'utilisation du projet. Pour les protocoles applicatifs certains n'ont pas été traités avec l'ensembles des options car il y en avait trop mais la plupart sont traités. 