#include "../include/include.h"

void affiche_bootp(char *packet, int niveau) {
    struct bootp *bootp_hdr = (struct bootp *)packet;
    switch (niveau) {
    case 1:
        printf("\n");
        printf("BOOTP  \n");
        break;
    case 2:
        printf("\n");
        printf("BOOTP : \n");
        printf("\n");
        printf("Type de message : %u", bootp_hdr->bp_op);
        if (bootp_hdr->bp_op == BOOTREPLY)
            printf("REPLY\n");
        else if (bootp_hdr->bp_op == BOOTREQUEST) {
            printf("REQUEST\n");
        }
        break;
    case 3:
        printf("\n");
        printf("BOOTP : \n");
        printf("\n");
        printf("Type de message : %u", bootp_hdr->bp_op);
        if (bootp_hdr->bp_op == BOOTREPLY)
            printf("REPLY\n");
        else if (bootp_hdr->bp_op == BOOTREQUEST) {
            printf("REQUEST\n");
        }
        printf("Hardware address type : %u\n -> Ethernet", bootp_hdr->bp_htype);
        printf("Hardware address lenght : %u\n", bootp_hdr->bp_hlen);
        printf("Gateway Hops : %u\n", bootp_hdr->bp_hops);
        printf("Transaction ID : 0x%x\n", ntohl(bootp_hdr->bp_xid));
        printf("Seconds since boot began : %us\n", bootp_hdr->bp_secs);
        printf("Flags : 0x%x\n", ntohs(bootp_hdr->bp_flags));
        printf("Client IP address : %s\n", inet_ntoa(bootp_hdr->bp_ciaddr));
        printf("Your IP address : %s\n", inet_ntoa(bootp_hdr->bp_yiaddr));
        printf("Server IP address : %s\n", inet_ntoa(bootp_hdr->bp_siaddr));
        printf("Gateway IP address : %s\n", inet_ntoa(bootp_hdr->bp_giaddr));
        printf("Client hardware address : ");
        affiche_addr_mac(bootp_hdr->bp_chaddr);
        printf("Server host name : %s\n", bootp_hdr->bp_sname);
        printf("Boot file name : %s\n", bootp_hdr->bp_file);
        affiche_bootp_options(bootp_hdr->bp_vend);
        break;
    }
}

void affiche_bootp_options(uint8_t *vend) {
    printf("Options : \n");
    uint8_t *options = vend + 4;
    int i = 0;
    while (vend[i] != 0xff) {
        switch (vend[i]) {
        case 0x00:
            printf("Pad\n");
            break;
        case 0x01:
            printf("Subnet mask : %s\n",
                   inet_ntoa(*(struct in_addr *)(vend + i + 2)));
            break;
        case 0x03:
            printf("Router : %s\n",
                   inet_ntoa(*(struct in_addr *)(vend + i + 2)));
            break;
        case 0x04:
            printf("Time server : %s\n",
                   inet_ntoa(*(struct in_addr *)(vend + i + 2)));
            break;
        case 0x05:
            printf("Name server : %s\n",
                   inet_ntoa(*(struct in_addr *)(vend + i + 2)));
            break;
        case 0x06:
            printf("Domain name server : %s\n",
                   inet_ntoa(*(struct in_addr *)(vend + i + 2)));
            break;
        case 0x07:
            printf("Log server : %s\n",
                   inet_ntoa(*(struct in_addr *)(vend + i + 2)));
            break;
        case 0x08:
            printf("Cookie server : %s\n",
                   inet_ntoa(*(struct in_addr *)(vend + i + 2)));
            break;
        case 0x09:
            printf("LPR server : %s\n",
                   inet_ntoa(*(struct in_addr *)(vend + i + 2)));
            break;
        case 0x0a:
            printf("Impress server : %s\n",
                   inet_ntoa(*(struct in_addr *)(vend + i + 2)));
            break;
        case 0x0b:
            printf("Resource location server : %s\n",
                   inet_ntoa(*(struct in_addr *)(vend + i + 2)));
            break;
        case 0x0c:
            printf("Host name : %s\n", vend + i + 2);
            break;
        case 0x0d:
            printf("Boot file size : %u\n", ntohs(*(uint16_t *)(vend + i + 2)));
            break;
        case 0x32:
            printf("Requested IP address : %s\n",
                   inet_ntoa(*(struct in_addr *)(vend + i + 2)));
            break;
        case 0x33:
            printf("IP address lease time : %u\n",
                   ntohl(*(uint32_t *)(vend + i + 2)));
            break;
        case 0x34:
            printf("Option overload : %u\n", vend[i + 2]);
            break;
        case 0x35:
            printf("DHCP message type : %u\n", vend[i + 2]);
            switch (*(options + 2)) {
            case DHCPDISCOVER:
                printf("DISCOVER");
                break;
            case DHCPOFFER:
                printf("OFFER");
                break;
            case DHCPREQUEST:
                printf("REQUEST");
                break;
            case DHCPDECLINE:
                printf("DECLINE");
                break;
            case DHCPACK:
                printf("ACK");
                break;
            case DHCPNAK:
                printf("NAK");
                break;
            case DHCPRELEASE:
                printf("RELEASE");
                break;
            case DHCPINFORM:
                printf("INFORM");
                break;
            }
            break;
        case 0x36:
            printf("Server identifier : %s\n",
                   inet_ntoa(*(struct in_addr *)(vend + i + 2)));
            break;
        case 0x37:
            printf("Parameter request list : %u\n", vend[i + 2]);
            break;
        case 0x38:
            printf("Message : %s\n", vend + i + 2);
            break;
        case 0x39:
            printf("Maximum DHCP message size : %u\n",
                   ntohs(*(uint16_t *)(vend + i + 2)));
            break;
        case 0x3a:
            printf("Renewal time value : %u\n",
                   ntohl(*(uint32_t *)(vend + i + 2)));
            break;
        case 0x3b:
            printf("Rebinding time value : %u\n",
                   ntohl(*(uint32_t *)(vend + i + 2)));
            break;
        case 0x3c:
            printf("Class identifier : %s\n", vend + i + 2);
            break;
        case 0x3d:
            printf("Client identifier : %s\n", vend + i + 2);
            break;
        default:
            printf("Option non développée : %u\n", vend[i]);
            break;
        }
    }
}