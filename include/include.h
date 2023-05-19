#ifndef INC
#define INC

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

#include "arg.h"
#include "arp.h"
#include "bootp.h"
#include "bootp2.h"
#include "dns.h"
#include "ethernet.h"
#include "ftp.h"
#include "http.h"
#include "imap.h"
#include "ip_4.h"
#include "ip_6.h"
#include "pop3.h"
#include "port_entree.h"
#include "smtp.h"
#include "tcp.h"
#include "telnet.h"
#include "udp.h"
#include "utils.h"

// main
#define BUFFSIZE 8192

#endif