#include "../include/include.h"

void affiche_udp(char *packet, int niveau, uint16_t taille) {
    struct udphdr *udp = (struct udphdr *)packet;
    switch (niveau) {
    case 1:
        printf("\n");
        printf("UDP \n");

        break;
    case 2:
        printf("\n");
        printf("UDP :\n");
        printf("\n");
        printf("port source: %i | ", ntohs(udp->source));
        printf("port destination : %i\n", ntohs(udp->dest));
        break;
    case 3:
        printf("\n");
        printf("UDP :\n");
        printf("\n");
        printf("port source : %u\n", ntohs(udp->source));
        printf("port destination : %u\n", ntohs(udp->dest));
        printf("taille : %u\n", ntohs(udp->len));
        printf("checksum : 0x%x\n", ntohs(udp->check));
    }
    port(ntohs(udp->uh_sport), ntohs(udp->uh_dport),
         packet + sizeof(struct udphdr), niveau,
         taille - sizeof(struct udphdr));
}
