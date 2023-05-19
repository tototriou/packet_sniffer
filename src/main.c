#include "../include/include.h"

void got_packet(u_char *args, const struct pcap_pkthdr *header,
                const u_char *packet);

int main(int argc, char *argv[]) {
    options_t options;
    parseArgs(argc, argv, &options);
    int nb = options.nb;
    pcap_t *p;
    if (options.action == ACTION_LIVE) {
        // pcap_t *p;
        char errbuf[PCAP_ERRBUF_SIZE];
        p = pcap_open_live("wlp2s0", BUFFSIZE, 1, 1000, errbuf);
        if (p == NULL) {
            printf("%s\n", errbuf);
            return 1;
        }

        // pcap_loop(p, nb, got_packet, (u_char *)&options.niveau);
    } else if (options.action == ACTION_OFF) {
        // pcap_t *p;
        char errbuf[PCAP_ERRBUF_SIZE];
        p = pcap_open_offline(options.inputFilename, errbuf);
        if (p == NULL) {
            printf("%s\n", errbuf);
            return 1;
        }

        // pcap_loop(p, nb, got_packet, (u_char *)&options.niveau);
    } else if (options.action == ACTION_DEVICE) {

        char errbuf[PCAP_ERRBUF_SIZE];
        p = pcap_open_live(options.device, BUFFSIZE, 1, 1000, errbuf);
        if (p == NULL) {
            printf("%s\n", errbuf);
            return 1;
        }
    }
    if (options.filtre == ACTION_BPF) {
        struct bpf_program fp;
        if (pcap_compile(p, &fp, options.bpf, 0, 0) == -1) {
            printf("pcap_compile error\n");
        }
        if (pcap_setfilter(p, &fp) == -1) {
            printf("pcap_setfilter error\n");
        }
    }
    pcap_loop(p, nb, got_packet, (u_char *)&options.niveau);
    // printf("Nombre de paquets : %i\n", nb_packet);
    return 0;
}

void got_packet(u_char *args, const struct pcap_pkthdr *header,
                const u_char *packet) {

    int niveau = args[0];
    (void)header;

    affiche_ethernet((char *)packet, niveau);
}
