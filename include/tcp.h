#ifndef TCP
#define TCP

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
 * @brief Permet l'affichage des informations TCP, pour le niveau de verbosité
 * 3 on fait l'appel de la fonction affiche_tcp_flags pour avoir le
 * décriptage totale de informatios TCP. L'algorithme passe a la suite grace à
 * la fonction port définie dans le fichier port_entree.
 *
 */

void affiche_tcp(char *ip, int niveau, uint16_t taille);

/**
 * @brief Permet l'affichage des flags TCP pour le décriptage total de la
 * trame.
 *
 */

void affiche_tcp_flags(uint8_t flags);

#endif