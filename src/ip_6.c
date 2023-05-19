#include "../include/include.h"

void affiche_ipv6(char *packet, int niveau) {
    struct ip6_hdr *ip = (struct ip6_hdr *)(packet);
    switch (niveau) {
    case 1:
        printf("\n");
        printf("IPV6 \n");

        break;
    case 2:
        printf("\n");
        printf("IPV6 :\n");
        printf("\n");
        printf("IP source  : ");
        affiche_addr_ipv6(ip->ip6_src);
        printf("\n");
        printf("IP dest  : ");
        affiche_addr_ipv6(ip->ip6_src);
        printf("\n");
        break;
    case 3:
        printf("\n");
        printf("IPV6 :\n");
        printf("\n");
        printf("IP source  : ");
        affiche_addr_ipv6(ip->ip6_src);
        printf("\n");
        printf("IP dest  : ");
        affiche_addr_ipv6(ip->ip6_src);
        printf("\n");
        printf("Flow : %.2x\n", ip->ip6_flow >> 8);
        printf("Payload Length : %u\n", ntohs(ip->ip6_plen));
        printf("Next header : 0x%x\n", ip->ip6_nxt);
        printf("Hop limit : %u\n", ip->ip6_hlim);
        printf("Version : %u\n", ip->ip6_vfc >> 4);
        printf("Traffic class : 0x%.2x\n", ip->ip6_flow >> 8);
        break;
    }
    int taille = ntohs(ip->ip6_plen);
    switch (ip->ip6_nxt) {
    case 0x11:
        affiche_udp(packet + sizeof(struct ip6_hdr), niveau, taille);
        break;
    case 0x06:
        affiche_tcp(packet + sizeof(struct ip6_hdr), niveau, taille);
        break;
    case 0x3a:
        printf("\n");
        printf("ICMPv6 (non traité)\n");
        printf("\n");
        break;
    }
}