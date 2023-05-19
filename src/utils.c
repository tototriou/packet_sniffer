#include "../include/include.h"

void affiche_addr_mac(uint8_t *addr) {
    for (int i = 0; i < 5; i++) {
        printf("%02x:", addr[i]);
    }
    printf("%02x", addr[5]);
}

void affiche_addr_ipv4(int32_t addr) {
    printf("%u.", addr & 0xff);
    printf("%u.", (addr >> 8) & 0xff);
    printf("%u.", (addr >> 16) & 0xff);
    printf("%u", (addr >> 24) & 0xff);
}

void affiche_addr_ipv6(struct in6_addr a) {
    uint32_t *addr = a.__in6_u.__u6_addr32;

    printf("%02x", addr[0] & 0xff);
    printf("%02x:", (addr[0] >> 8) & 0xff);
    printf("%02x", (addr[0] >> 16) & 0xff);
    printf("%02x:", (addr[0] >> 24) & 0xff);
    printf("%02x", addr[1] & 0xff);
    printf("%02x:", (addr[1] >> 8) & 0xff);
    printf("%02x", (addr[1] >> 16) & 0xff);
    printf("%02x:", (addr[1] >> 24) & 0xff);
    printf("%02x", addr[2] & 0xff);
    printf("%02x:", (addr[2] >> 8) & 0xff);
    printf("%02x", (addr[2] >> 16) & 0xff);
    printf("%02x:", (addr[2] >> 24) & 0xff);
    printf("%02x", addr[3] & 0xff);
    printf("%02x:", (addr[3] >> 8) & 0xff);
    printf("%02x", (addr[3] >> 16) & 0xff);
    printf("%02x", (addr[3] >> 24) & 0xff);
}
