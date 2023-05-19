#ifndef IMAP
#define IMAP

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
 * @brief Permet l'affichage des informations IMAP, pour le niveau de verbosité
 * 3 on fait l'appel de la fonction affiche_imap_options pour avoir le
 * décriptage totale de informatios IMAP.
 *
 */

void affiche_imap(char *packet, int niveau, uint16_t taille);

/**
 * @brief Permet l'affichage des options de IMAP pour avoir le décriptage
 * complet de la trame.
 *
 */

void affiche_imap_options(char *packet);

#endif