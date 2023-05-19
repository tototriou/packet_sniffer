#ifndef UDP
#define UDP

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
 * @brief Permet l'affichage des informations udp. Le decriptage se poursuit
 * grace a la fonction port définie dans le fichier port_entree.
 *
 */

void affiche_udp(char *ip, int niveau, uint16_t taille);

#endif