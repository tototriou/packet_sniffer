#include "../include/include.h"

void affiche_ftp(char *packet, int niveau, uint16_t taille) {
    switch (niveau) {
    case 1:
        printf("\n");
        printf("FTP \n");

        break;
    case 2:
        printf("\n");
        printf("FTP :\n");
        printf("\n");
        printf("%s", packet);
        break;
    case 3:
        printf("\n");
        printf("FTP :\n");
        printf("\n");
        for (int i = 0; i < taille; i++) {
            if (isprint(packet[i]))
                printf("%c", packet[i]);
            else
                printf(".");
        }
        break;
    }
}
