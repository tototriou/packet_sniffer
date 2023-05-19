#ifndef POP3
#define POP3

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
 * @brief Permet l'affichage des informations POP3, pour le niveau de verbosité
 * 3 on fait l'appel de la fonction affiche_pop3_options pour avoir le
 * décriptage totale de informatios POP3.
 *
 */

void affiche_pop3(char *packet, int niveau, uint16_t taille);

/**
 * @brief Permet l'affichage des options de POP3 pour avoir le décriptage
 * complet de la trame.
 *
 */

void affiche_pop3_options(char *packet);

#endif