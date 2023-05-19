#include "../include/include.h"

void affiche_ipv4(char *packet, int niveau) {
    struct ip *ip = (struct ip *)(packet);
    switch (niveau) {
    case 1:
        printf("\n");
        printf("IPV4 \n");

        break;
    case 2:
        printf("\n");
        printf("IPV4 :\n");
        printf("\n");
        printf("@IP source  : %s | ",
               inet_ntoa(*(struct in_addr *)&ip->ip_src));
        printf("@IP dest  : %s\n", inet_ntoa(*(struct in_addr *)&ip->ip_dst));
        printf("\n");
        break;
    case 3:
        printf("\n");
        printf("IPV4 :\n");
        printf("\n");
        printf("IP source : %s\n", inet_ntoa(ip->ip_src));
        printf("IP dest : %s\n", inet_ntoa(ip->ip_dst));
        printf("IP version : %i\n", ip->ip_v);
        printf("IP header length : %i (%i bytes)\n", ip->ip_hl, ip->ip_hl * 4);
        printf("Type of Service : %i\n", ip->ip_tos);
        printf("Total length : %u\n", ntohs(ip->ip_len));
        printf("Transaction id : 0x%.2x\n", ntohs(ip->ip_id));
        printf("Fragment offset field : 0x%.2x\n", ntohs(ip->ip_off));
        printf("Checksum : 0x%x\n", ntohs(ip->ip_sum));
        printf("Time to live : %i\n", ip->ip_ttl);
        break;
    }
    int taille = ntohs(ip->ip_len) - ip->ip_hl * 4;
    switch (ip->ip_p) {
    case 0x11:
        affiche_udp(packet + (ip->ip_hl * 4), niveau, taille);
        break;
    case 0x06:
        affiche_tcp(packet + (ip->ip_hl * 4), niveau, taille);
        break;
    case 0x01:
        printf("ICMP \n");
        break;
    }
}