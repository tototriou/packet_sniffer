#include "../include/include.h"

void affiche_dns(char *packet, int niveau) {
    // char *p = packet + sizeof(struct dns_hdr);
    struct dns_hdr *hd = (struct dns_hdr *)packet;
    int offset = 0;

    switch (niveau) {
    case 1:
        printf("\n");
        printf("DNS \n");

        break;
    case 2:
        printf("\n");
        printf("DNS \n");
        printf("\n");
        if (!hd->query)
            printf("QUERY |");
        else
            printf("RESPOND |");
        // printf("opcode : %u\n",ntohs(hd->opcode));
        printf("Taille : %u | ", htons(hd->length));
        printf("Id : %u | ", htons(hd->id));
        printf("Nombre de questions: %u |", ntohs(hd->nb_question));
        printf("Nombre de Answer : %u |", ntohs(hd->nb_answer));
        printf("nombre de Autority : %u |", ntohs(hd->nb_authority));
        printf("nombre de Additional : %u\n", ntohs(hd->nb_additional));

        break;
    case 3:
        printf("\n");
        printf("DNS \n");
        printf("\n");
        printf("Taille : %u\n ", htons(hd->length));
        printf("Id : %u\n", htons(hd->id));
        if (!hd->query) {
            printf("query\n");
            printf("opcode : %u\n", hd->opcode);
            printf("authoritative : %u\n", hd->authoritative);
            printf("truncated : %u\n", hd->truncated);
            printf("recursion_desired : %u\n", hd->recursion_desired);
            printf("recursion_available : %u\n", hd->recursion_available);
            printf("Z : %u\n", hd->Z);
            printf("answer_authenticated : %u\n", hd->answer_authenticated);
            printf("non_authenticated_data : %u\n", hd->non_authenticated_data);
            printf("reply_code : %u\n", hd->reply_code);

        } else {
            printf("respond\n");
            printf("opcode : %u\n", hd->opcode);
            printf("authoritative : %u\n", hd->authoritative);
            printf("truncated : %u\n", hd->truncated);
            printf("recursion_desired : %u\n", hd->recursion_desired);
            printf("recursion_available : %u\n", hd->recursion_available);
            printf("Z : %u\n", hd->Z);
            printf("answer_authenticated : %u\n", hd->answer_authenticated);
            printf("non_authenticated_data : %u\n", hd->non_authenticated_data);
            printf("reply_code : %u\n", hd->reply_code);
        }
        printf("Nombre de questions: %u\n", ntohs(hd->nb_question));
        printf("Nombre de Answer : %u\n", ntohs(hd->nb_answer));
        printf("nombre de Autority : %u\n", ntohs(hd->nb_authority));
        printf("nombre de Additional : %u\n", ntohs(hd->nb_additional));

        offset = print_query(packet, offset);
    }
}

int dns_name(char *packet, int offset) {
    printf("Nom : ");
    while (packet[offset] != 0x00) {
        uint8_t size = packet[offset];
        for (int i = 0; i <= (size); i++)
            printf("%c", packet[offset + i]);
        printf(".");
        offset += 1 + packet[offset];
    }
    printf("\n");
    return offset;
}

int print_query(char *packet, int offset) {
    offset = sizeof(struct dns_hdr);
    offset = dns_name(packet, offset);

    struct dns_question *query = (struct dns_question *)packet;
    printf("Type : %u\n", ntohs(query->type));
    printf("Class : %u\n", ntohs(query->class_code));
    offset += sizeof(struct dns_question);
    return offset;
}

int print_respond(char *packet, int offset) {
    (void)packet;
    (void)offset;
    return 0;
}