#ifndef UTILS
#define UTILS

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

// main
#define BUFFSIZE 8192

// fonction utiles

/**
 *
 * @brief affiche une addresse mac
 *
 **/

void affiche_addr_mac(uint8_t *addr);

/**
 *
 * @brief affiche une addresse ipv4
 *
 **/

void affiche_addr_ipv4(int32_t addr);

/**
 *
 * @brief affiche une addresse ipv6
 *
 **/

void affiche_addr_ipv6(struct in6_addr a);

#endif