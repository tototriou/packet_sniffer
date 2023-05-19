#ifndef DNS
#define DNS

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
 * @brief fonction principale d'affichage de dns en fonction du niveau de
 * verbosité, au niveau 3, on fait appel a print_query pour plus de
 * détails
 *
 */

void affiche_dns(char *packet, int niveau);

/**
 * @brief permet l'affichage complet du message DNS octect par octet sans faire
 * la différence entre requete et reponse. Pour plus de visibilité et de détail
 * une fonction print_respond peut-etre mis en place. Cette fonction fait appel
 * a dns_name pour afficher le nom.
 *
 */

int print_query(char *packet, int offset);

/**
 * @brief permet d'afficher le nom car on ne connait pas sa longueur on sait
 * juste qu'il se termine par 0x00. Cette fonctionne affiche donc tous les
 * octets jusqu'a rencontrer 0x00.
 *
 */

int dns_name(char *packet, int offset);

/**
 * @brief fonction pas développée mais serait utile pour différencier
 * l'affichage entre une requete et une reponse. l'algorithme fonctionne meme
 * sans l'implémentation de cette fonction.
 *
 */

int print_respond(char *packet, int offset);

/**
 * @brief structure permettant de stocker l'ensemble de l'en-tete dns
 *
 */

struct dns_hdr {
    uint16_t length;
    uint16_t id;
    // premier octet
    uint16_t recursion_desired : 1;
    uint16_t truncated : 1;
    uint16_t authoritative : 1;
    uint16_t opcode : 4;
    uint16_t query : 1;
    // deuxieme octet
    uint16_t reply_code : 4;
    uint16_t non_authenticated_data : 1;
    uint16_t answer_authenticated : 1;
    uint16_t Z : 1;
    uint16_t recursion_available : 1;
    // suite
    uint16_t nb_question;
    uint16_t nb_answer;
    uint16_t nb_authority;
    uint16_t nb_additional;
};

/**
 * @brief Permet de différencier plus facilement la classe et le type dans les
 * requete dns.
 *
 */

struct dns_question {
    uint16_t type;
    uint16_t class_code;
};

/**
 * @brief structure prete pour la fonction print_respond mais pas implémenter.
 *
 */

struct dns_answer {
    uint16_t type;
    uint16_t class_code;
    uint32_t TTL;
    uint16_t RDlenght;
};

#endif