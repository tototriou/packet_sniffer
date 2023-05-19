#ifndef SMTP
#define SMTP

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
 * @brief Permet l'affichage des informations SMTP, pour le niveau de verbosité
 * 3 on fait l'appel de la fonction affiche_smtp_flags pour avoir le
 * décriptage totale de informatios SMTP.
 *
 */

void affiche_smtp(char *ip, int niveau, uint8_t taille, int port);

/**
 * @brief Permet l'affichage des flags SMTP pour le décriptage total de la
 * trame.
 *
 */

void affiche_smtp_flags(char *packet, int taille);

#endif