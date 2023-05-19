#include "../include/include.h"

int nb_packet = 0;
void affiche_ethernet(char *packet, int niveau) {
    struct ether_header *header = (struct ether_header *)packet;
    printf("______________________\n");
    nb_packet++;
    printf("trame numéro %i\n", nb_packet);
    switch (niveau) {
    case 1:
        printf("\n");
        printf("ETHERNET \n");

        break;
    case 2:
        printf("\n");
        printf("ETHERNET :\n");
        printf("\n");
        printf("@MAC Source -> Destination : %.2x:%.2x:%.2x:%.2x:%.2x:%.2x ->",
               header->ether_shost[0], header->ether_shost[1],
               header->ether_shost[2], header->ether_shost[3],
               header->ether_shost[4], header->ether_shost[5]);
        printf(" %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n", header->ether_dhost[0],
               header->ether_dhost[1], header->ether_dhost[2],
               header->ether_dhost[3], header->ether_dhost[4],
               header->ether_dhost[5]);
        break;

    case 3:
        printf("\n");
        printf("ETHERNET :\n");
        printf("\n");
        printf("MAC Source : %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n",
               header->ether_shost[0], header->ether_shost[1],
               header->ether_shost[2], header->ether_shost[3],
               header->ether_shost[4], header->ether_shost[5]);
        printf("MAC Destination : %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n",
               header->ether_dhost[0], header->ether_dhost[1],
               header->ether_dhost[2], header->ether_dhost[3],
               header->ether_dhost[4], header->ether_dhost[5]);
        printf("type : %#2x \n", ntohs(header->ether_type));
        break;
    default:
        break;
    }
    switch (ntohs(header->ether_type)) {
    case ETHERTYPE_ARP: // 0x0806
        affiche_arp(packet + sizeof(struct ether_header), header->ether_dhost,
                    header->ether_shost, niveau);
        break;

    case ETHERTYPE_IP: // 0x0800
        affiche_ipv4(packet + sizeof(struct ether_header), niveau);
        break;

    case ETHERTYPE_IPV6: // 0x08dd
        affiche_ipv6(packet + sizeof(struct ether_header), niveau);
        break;
    default:
        break;
    }
}