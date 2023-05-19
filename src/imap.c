#include "../include/include.h"

void affiche_imap(char *packet, int niveau, uint16_t taille) {
    switch (niveau) {
    case 1:
        printf("\n");
        printf("IMAP \n");

        break;
    case 2:
        printf("\n");
        printf("IMAP :\n");
        printf("\n");
        if (taille)
            affiche_imap_options(packet);
        else
            printf("Pas d information IMAP\n");
        break;
    case 3:
        printf("\n");
        printf("IMAP :\n");
        printf("\n");
        if (taille) {
            for (int i = 0; i < taille; i++) {
                if (isprint(packet[i]))
                    printf("%c", packet[i]);
                else
                    printf(".");
            }
        } else
            printf("Pas d information IMAP\n");

        break;
    }
    printf("\n");
}

void affiche_imap_options(char *packet) {
    if (strstr(packet, "OK LOGIN") != NULL) {
        printf("OK LOGIN");
    } else if (strstr(packet, "LOGIN") != NULL) {
        printf("LOGIN");
    } else if (strstr(packet, "SELECT") != NULL) {
        printf("SELECT");
    } else if (strstr(packet, "NO") != NULL) {
        printf("NO");
    } else if (strstr(packet, "BYE LOGOUT") != NULL) {
        printf("BYE LOGOUT");
    } else if (strstr(packet, "LOGOUT") != NULL) {
        printf("LOGOUT");
    } else if (strstr(packet, "NOOP") != NULL) {
        printf("NOOP");
    } else if (strstr(packet, "LIST") != NULL) {
        printf("LIST");
    } else if (strstr(packet, "CREATE") != NULL) {
        printf("CREATE");
    } else if (strstr(packet, "DELETE") != NULL) {
        printf("DELETE");
    } else if (strstr(packet, "RENAME") != NULL) {
        printf("RENAME");
    } else if (strstr(packet, "SEARCH ALL") != NULL) {
        printf("SEARCH ALL");
    } else if (strstr(packet, "OK") != NULL) {
        printf("OK");
    } else {
        printf("Non traité");
    }
}