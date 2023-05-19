#include "../include/include.h"

void port(int source, int destination, char *packet, int niveau,
          uint16_t taille) {
    switch (source) {
    case 21:
        affiche_ftp(packet, niveau, taille);
        break;
    case 25:
        affiche_smtp(packet, niveau, taille, 0);
        break;
    case 587:
        affiche_smtp(packet, niveau, taille, 0);
        break;
    case 465:
        affiche_smtp(packet, niveau, taille, 0);
        break;
    case 53:
        affiche_dns(packet, niveau);
        break;
    case 67:
        affiche_bootp(packet, niveau);
        break;
    case 68:
        affiche_bootp(packet, niveau);
        break;
    case 80:
        affiche_http(packet, niveau, taille);
        break;
    case 110:
        affiche_pop3(packet, niveau, taille);
        break;
    case 443:
        affiche_imap(packet, niveau, taille);
        break;
    case 23:
        affiche_telnet(packet, niveau, taille);
        break;
    default:
        switch (destination) {
        case 21:
            affiche_ftp(packet, niveau, taille);
            break;
        case 25:
            affiche_smtp(packet, niveau, taille, 1);
            break;
        case 587:
            affiche_smtp(packet, niveau, taille, 1);
            break;
        case 465:
            affiche_smtp(packet, niveau, taille, 1);
            break;
        case 53:
            affiche_dns(packet, niveau);
            break;
        case 67:
            affiche_bootp(packet, niveau);
            break;
        case 68:
            affiche_bootp(packet, niveau);
            break;

        case 80:
            affiche_http(packet, niveau, taille);
            break;

        case 110:
            affiche_pop3(packet, niveau, taille);
            break;

        case 443:
            affiche_imap(packet, niveau, taille);
            break;
        case 23:
            affiche_telnet(packet, niveau, taille);
            break;
        default:
            printf("\nPort non reconnu\n");
            break;
        }
        break;
    }
}