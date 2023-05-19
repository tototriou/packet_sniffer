#include "../include/include.h"

void affiche_pop3(char *packet, int niveau, uint16_t taille) {
    switch (niveau) {
    case 1:
        printf("\n");
        printf("POP3 \n");

        break;
    case 2:
        printf("\n");
        printf("POP3 :\n");
        printf("\n");
        if (taille)
            affiche_pop3_options(packet);
        else
            printf("Pas d information POP3\n");
        break;
    case 3:
        printf("\n");
        printf("POP3 :\n");
        printf("\n");
        if (taille) {
            for (int i = 0; i < taille; i++) {
                if (isprint(packet[i]))
                    printf("%c", packet[i]);
                else
                    printf(".");
            }
        } else
            printf("Pas d information POP3\n");

        break;
    }
    printf("\n");
}

void affiche_pop3_options(char *packet) {
    if (strstr(packet, "USER") != NULL) {
        printf("USER");
    } else if (strstr(packet, "PASS") != NULL) {
        printf("PASS");
    } else if (strstr(packet, "STAT") != NULL) {
        printf("STAT");
    } else if (strstr(packet, "LIST") != NULL) {
        printf("LIST");
    } else if (strstr(packet, "UIDL") != NULL) {
        printf("UIDL");
    } else if (strstr(packet, "RETR") != NULL) {
        printf("RETR");
    } else if (strstr(packet, "DELE") != NULL) {
        printf("DELE");
    } else if (strstr(packet, "TOP") != NULL) {
        printf("TOP");
    } else if (strstr(packet, "LAST") != NULL) {
        printf("LAST");
    } else if (strstr(packet, "RSET") != NULL) {
        printf("RSET");
    } else if (strstr(packet, "NOOP") != NULL) {
        printf("NOOP");
    } else if (strstr(packet, "QUIT") != NULL) {
        printf("QUIT");
    } else if (strstr(packet, "+OK") != NULL) {
        printf("+OK");
    } else if (strstr(packet, "-ERR") != NULL) {
        printf("-ERR");
    } else {
        printf("Pas traité");
    }
}
