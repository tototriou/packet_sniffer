#ifndef ETHERNET
#define ETHERNET

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
 * @brief premiere fonction d'affichage permet de séparer les paquets et en
 * fonction du protocole envoyer sur les différentes fonctions IPv4,IPv6,...
 *
 *
 */

void affiche_ethernet(char *packet, int niveau);

#endif