#ifndef BOOTP
#define BOOTP

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
 * @brief fonction principale d'affichage de bootp en fonction du niveau de
 * verbosité, au niveau 3, on fait appel a affiche_bootp_options pour plus de
 * détails
 *
 */

void affiche_bootp(char *packet, int niveau);

/**
 * @brief permet d'afficher l'ensemble des informations bootp ainsi que toutes
 * les options
 *
 */

void affiche_bootp_options(uint8_t *vend);

#endif