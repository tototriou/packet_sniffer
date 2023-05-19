#include "../include/include.h"

void cleanOptions(options_t *options) {

    if (options->inputFile)
        fclose(options->inputFile);
}

void checkOptionsValidity(options_t *options) {

    if (options->action == ACTION_UNKNOWN) {
        fprintf(stderr, "il faut spécifier une options\n");
        printUsage();
        abort();
    }

    if (options->inputFilename == NULL && options->action == ACTION_OFF) {
        fprintf(stderr, "il faut un fichier d'entree pour l'analyse offline\n");
        exit(1);
    }
    if (options->niveau == -1) {
        fprintf(stderr, "le niveau de verbosité est obligatoire -v <1..3>\n");
        exit(1);
    }
    if (options->niveau <= 0 || options->niveau > 3) {
        fprintf(stderr, "le niveau de verbosité doit etre entre 1 et 3 voir "
                        "help pour plus d information (-h)\n");
        exit(1);
    }
}

void initOptions(options_t *options) {
    options->action = ACTION_LIVE;
    options->inputFile = NULL;
    options->niveau = -1;
    options->filtre = 0;
    options->device = NULL;
    options->nb = -1;
}

void parseArgs(int argc, char **argv, options_t *options) {

    initOptions(options);

    int c;
    while ((c = getopt(argc, argv, "hi:f:o:v:p:n:")) != -1) {
        switch (c) {
        case 'h':
            printUsage();
            exit(1);
        case 'i':
            options->action = ACTION_DEVICE;
            options->device = optarg;
            break;
        case 'f':
            options->filtre = ACTION_BPF;
            options->bpf = optarg;
            break;
        case 'o':
            options->action = ACTION_OFF;
            options->inputFilename = optarg;
            options->inputFile = fopen(optarg, "r");
            break;
        case 'v':
            options->niveau = atoi(optarg);
            break;
        case 'p':
            options->protocol = optarg;
            break;
        case 'n':
            options->nb = atoi(optarg);
            break;

        case '?':
            if (optopt == 'o' || optopt == 'v' || optopt == 'i' ||
                optopt == 'f' || optopt == 'p' || optopt == 'n')
                fprintf(stderr, "Option -%c requires an argument.\n", optopt);
            else if (isprint(optopt))
                fprintf(stderr, "Unknown option `-%c'.\n", optopt);
            else {
                options->action = ACTION_UNKNOWN;
                fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
            }
            printUsage();
            abort();
        default:
            printUsage();
            abort();
        }
    }
    checkOptionsValidity(options);
}

void printUsage(void) {
    printf("usage: ./fichier OPTIONS\n"
           "options:\n"
           "\t-i <interface> : interface pour l’analyse live\n"
           "\t-o <fichier> : fichier d’entrée pour l’analyse offline\n"
           "\t-f <filtre> : filtre BPF (optionnel)\n"
           "\t-v <1..3> : niveau de verbosité (1=très concis ; 2=synthétique ; "
           "\t-n <nombre> le nombre de paquet a analyser\n"
           "3=complet)\n");
}
