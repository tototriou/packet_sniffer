#include "../include/include.h"

void affiche_tcp(char *packet, int niveau, uint16_t taille) {
    struct tcphdr *tcp = (struct tcphdr *)(packet);
    switch (niveau) {
    case 1:
        printf("\n");
        printf("TCP \n");

        break;
    case 2:
        printf("\n");
        printf("TCP :\n");
        printf("\n");
        printf("Port Source -> Destination : %d -> %d\n", ntohs(tcp->th_sport),
               ntohs(tcp->th_dport));
        break;
    case 3:
        printf("\n");
        printf("TCP :\n");
        printf("\n");
        printf("Port Source: %d\n", ntohs(tcp->th_sport));
        printf("Port Destination: %d\n", ntohs(tcp->th_dport));
        printf("Sequence number : 0x%.2x (%u)\n", tcp->th_seq,
               ntohl(tcp->th_seq));
        printf("Acknowledgement number : 0x%.2x (%u)\n", tcp->th_ack,
               ntohl(tcp->th_ack));
        printf("Data offset : %i\n", tcp->th_off);
        printf("Flags : 0x%.2x ", tcp->th_flags);
        affiche_tcp_flags(tcp->th_flags);
        printf("Window : %u\n", ntohs(tcp->th_win));
        printf("Checksum : 0x%x\n", ntohs(tcp->th_sum));
        printf("Urgent Pointer : %.2x\n", tcp->th_urp);
        break;
    }
    port(ntohs(tcp->th_sport), ntohs(tcp->th_dport), packet + 4 * tcp->th_off,
         niveau, taille - 4 * tcp->th_off);
}

void affiche_tcp_flags(uint8_t flags) {
    if (flags & TH_FIN)
        printf(" fin");
    if (flags & TH_SYN)
        printf(" syn");
    if (flags & TH_RST)
        printf(" reset");
    if (flags & TH_PUSH)
        printf(" push");
    if (flags & TH_ACK)
        printf(" ack");
    if (flags & TH_URG)
        printf(" urgent");
    printf("\n");
}
