#ifndef ARP
#define ARP

#include <ctype.h>
#include <inttypes.h>
#include <net/ethernet.h>
#include <net/if_arp.h>
#include <netinet/ether.h>
#include <netinet/ip.h>
#include <netinet/ip6.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <string.h>
#include <sys/errno.h>
#include <unistd.h>

/**
 *
 * @brief affiche @mac source et destination puis fais appel à affiche_arp_info
 * pour plus de d'information pour le niveau 3 de verbosité
 *
 */

void affiche_arp(char *packet, uint8_t src[6], uint8_t dest[6], int niveau);

/**
 *
 * @brief affiche :
 *          Format of hardware address.
 *          Format of protocol address.
 *          Length of hardware address.
 *          Length of protocol address.
 *          ARP opcode (command).
 *
 */

void affiche_arp_info(struct arphdr *arp);

/**
 * @brief permet d afficher les différentes adresses de l'expéditaire et du
 * destinataire
 *
 */
void affiche_arp_addr(char *packet);

#endif