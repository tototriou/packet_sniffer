#include "../include/include.h"

void affiche_http(char *packet, int niveau, uint16_t taille) {
    switch (niveau) {
    case 1:
        printf("\n");
        printf("HTTP \n");

        break;
    case 2:
        printf("\n");
        printf("HTTP :\n");
        printf("\n");
        if (taille)
            affiche_http_options(packet);
        else
            printf("Pas d information HTTP\n");
        break;
    case 3:
        printf("\n");
        printf("HTTP :\n");
        printf("\n");
        if (taille) {
            for (int i = 0; i < taille; i++) {
                if (isprint(packet[i]))
                    printf("%c", packet[i]);
                else
                    printf(".");
            }
        } else
            printf("Pas d information HTTP\n");

        break;
    }
    printf("\n");
}

void affiche_http_options(char *packet) {
    if (strstr(packet, "GET") != NULL) {
        printf("GET");
    } else if (strstr(packet, "HEAD") != NULL) {
        printf("HEAD");
    } else if (strstr(packet, "POST") != NULL) {
        printf("POST");
    } else if (strstr(packet, "PUT") != NULL) {
        printf("PUT");
    } else if (strstr(packet, "DELETE") != NULL) {
        printf("DELETE");
    } else if (strstr(packet, "CONNECT") != NULL) {
        printf("CONNECT");
    } else if (strstr(packet, "OPTIONS") != NULL) {
        printf("OPTIONS");
    } else if (strstr(packet, "TRACE") != NULL) {
        printf("TRACE");
    } else if (strstr(packet, "PATCH") != NULL) {
        printf("PATCH");
    } else {
        printf("OK");
    }
}
