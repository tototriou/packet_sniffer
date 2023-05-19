#include "../include/include.h"

void affiche_smtp(char *packet, int niveau, uint8_t taille, int port) {
    switch (niveau) {
    case 1:
        printf("\n");
        printf("SMTP \n");

        break;
    case 2:
        printf("\n");
        printf("SMTP :\n");
        printf("\n");
        if (port)
            printf("Réponse\n");
        else
            printf("Requête\n");
        break;
    case 3:
        printf("\n");
        printf("SMTP :\n");
        printf("\n");
        if (port)
            printf("Réponse\n");
        else
            printf("Requête\n");
        if (taille)
            affiche_smtp_flags(packet, taille);
        else
            printf("Pas d information SMTP\n");
        break;
    }
}

void affiche_smtp_flags(char *packet, int taille) {
    int i;
    for (i = 0; i < taille; i++) {
        if (isprint(packet[i])) {
            printf("%c", packet[i]);
        } else {
            printf(".");
        }
    }
    printf("\n");
}
/*
void affiche_smtp_flags(char *packet) {
    if (strstr(packet, "HELO") != NULL) {
        printf("HELO");
    }
    if (strstr(packet, "MAIL") != NULL) {
        printf("MAIL");
    }
    if (strstr(packet, "RCPT") != NULL) {
        printf("RCPT");
    }
    if (strstr(packet, "DATA") != NULL) {
        printf("DATA");
    }
    if (strstr(packet, "QUIT") != NULL) {
        printf("QUIT");
    }
    if (strstr(packet, "EHLO") != NULL) {
        printf("EHLO");
    }
    if (strstr(packet, "AUTH") != NULL) {
        printf("AUTH");
    }
    if (strstr(packet, "STARTTLS") != NULL) {
        printf("STARTTLS");
    }
    if (strstr(packet, "HELP") != NULL) {
        printf("HELP");
    }
}

void affiche_smtp_flags_respond(char *packet) {
    int flag = 16*16*packet[2]+16*packet[1]+packet[0];
    switch (flag) {
        case 101 :
            printf("101 : le serveur incapable est incapable de se connecter");
            break;
        case 111 :
            printf("111 : connexion refusée");
            break;
        case 211 :
            printf("Message d’état du système ou réponse d’aide.");
            break;
        case 214 :
            printf("214 : Une réponse à la commande HELP.");
            break;
        case 220 :
            printf("220 : Le serveur SMTP est prêt.");
            break;
        case 221 :
            printf("221 : Le serveur SMTP a terminé la session.");
            break;
        case 235 :
            printf("235 : L’authentification est réussie.");
            break;
        case 250 :
            printf("250 : La commande a été acceptée.");
            break;
        case 251 :
            printf("251 : L’utilisateur n’est pas local mais le serveur accepte
de le transférer."); break; case 252 : printf("252 : La commande n’a pas été
exécutée car le serveur ne peut pas vérifier que l’utilisateur est local.");
            break;
        case 354 :
            printf("354 : Le serveur attend une ligne vide avec un point
seul."); break; case 421 : printf("421 : Le serveur SMTP est indisponible.");
            break;
        case 422 :
            printf("422 : la boite mail est pleine");
            break;
        case 431 :
            printf("431 : Le serveur n’a pas assez de mémoire pour traiter la
commande."); break; case 432 : printf("432 : Le fichier de configuration du
serveur est corrompu."); break; case 450 : printf("450 : La commande n’a pas été
exécutée car le serveur ne peut pas vérifier que l’utilisateur est local.");
            break;
        case 451 :
            printf("451 : La commande n’a pas été exécutée car le serveur ne
peut pas vérifier que l’utilisateur est local."); break;
}
*/