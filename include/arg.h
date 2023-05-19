#ifndef ARG
#define ARG

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



typedef enum action_t {
    ACTION_UNKNOWN,
    ACTION_LIVE,
    ACTION_BPF,
    ACTION_OFF,
    ACTION_DEVICE,
} action_t;

/**
 * @brief structure permettant de stocker les différentes options entées en
 * lignes de commande
 *
 */

typedef struct options_t {
    action_t action;
    int niveau;
    uint64_t filtre;
    char *bpf;
    char *inputFilename;
    FILE *inputFile;
    char *device;
    char *protocol;
    int nb;
} options_t;

/**
 * @brief parse les arguments et reconnait les bonnes opttions de commandes
 *
 */

void parseArgs(int argc, char **argv, options_t *options);

/**
 * @brief permet de fermer le fichier si l option -f est activée
 *
 */

void cleanOptions(options_t *options);

/**
 * @brief affiche les différentes options de lignes de commandes possibles
 *
 */

void printUsage(void);

#endif
