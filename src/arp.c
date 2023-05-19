#include "../include/include.h"

void affiche_arp(char *packet, uint8_t src[6], uint8_t dest[6], int niveau) {
    struct arphdr *arp = (struct arphdr *)packet;
    switch (niveau) {
    case 1:
        printf("\n");
        printf("ARP \n");
        break;
    case 2:
        printf("\n");
        printf("ARP \n");
        printf("\n");
        printf("@MAC source -> destinataire :");
        affiche_addr_mac(src);
        printf(" -> ");
        affiche_addr_mac(dest);
        printf("\n");
        break;
    case 3:
        printf("\n");
        printf("ARP \n");
        printf("\n");
        affiche_arp_addr(packet);
        affiche_arp_info(arp);
        break;
    }
}

void affiche_arp_info(struct arphdr *arp) {
    /* Format of hardware address.  */

    printf("Format de l'adresse hardware : ");
    switch (ntohs(arp->ar_hrd)) {
    case ARPHRD_ETHER:
        printf("Ethernet 10/100Mbps \n");
        break;
    case ARPHRD_EETHER:
        printf("Experimental Ethernet\n");
        break;
    case ARPHRD_IEEE802:
        printf("IEEE 802.2 Ethernet/TR/TB \n");
        break;
    case ARPHRD_ARCNET:
        printf("ARCnet \n");
        break;
    case ARPHRD_IEEE1394:
        printf("IEEE 1394 IPv4 - RFC 2734 \n");
        break;
    case ARPHRD_EUI64:
        printf("EUI-64 \n");
        break;
    default:
        printf("autre que ethernet,experimental ethernet, iEEE 802.2, arcnet, "
               "IEEE 1394, EUI -64 \n");
    }

    /* Format of protocol address.  */

    printf("type de protocole : %u", ntohs(arp->ar_pro));
    if (ntohs(arp->ar_pro) == 0x0800)
        printf(" (ipv4)");
    if (ntohs(arp->ar_pro) == 0x86dd)
        printf(" (ipv6)");
    printf("\n");

    /* Length of hardware address.  */

    printf("length of hardware protocol address: %u\n", arp->ar_hln);

    /* Length of protocol address.  */

    printf("length of protocol address: %u\n", arp->ar_pln);

    /* ARP opcode (command).  */

    printf("OpCode: %u  ", arp->ar_op);
}

void affiche_arp_addr(char *packet) {
    struct ether_arp *arp = (struct ether_arp *)packet;
    printf("arp_sha : %s, ", ether_ntoa((struct ether_addr *)&arp->arp_sha));
    printf("arp_spa : %s, ", inet_ntoa(*(struct in_addr *)&arp->arp_spa));
    printf("arp_tha : %s, ", ether_ntoa((struct ether_addr *)&arp->arp_tha));
    printf("arp_tpa : %s\n", inet_ntoa(*(struct in_addr *)&arp->arp_tpa));
}
