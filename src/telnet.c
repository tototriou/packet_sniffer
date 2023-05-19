#include "../include/include.h"

void affiche_telnet(char *packet, int niveau, uint16_t taille) {
    switch (niveau) {
    case 1:
        printf("\n");
        printf("TELNET \n");

        break;
    case 2:
        printf("\n");
        printf("TELNET :\n");
        printf("\n");
        if (taille)
            printf("taille : %d\n", taille);
        else
            printf("Pas d information TELNET\n");

        break;
    case 3:
        printf("\n");
        printf("TELNET :\n");
        printf("\n");
        affiche_telnet_options(packet, taille);
        break;
    }
}

void affiche_telnet_options(char *packet, uint16_t taille) {
    int i;
    uint8_t packet2;
    if (taille) {
        for (i = 0; i < taille; i++) {
            packet2 = packet[i];
            printf("0x%02x ", packet2);
            if (!(i % 3 == 2)) {

                printf(" : ");

                if (packet2 == 0xff)
                    printf("IAC ");

                else if (packet2 == 0xfb)
                    printf("WILL ");

                else if (packet2 == 0xfc)
                    printf("WONT ");

                else if (packet2 == 0xfd)
                    printf("DO ");

                else if (packet2 == 0xfe)
                    printf("DONT ");

                else if (packet2 == 0xfa)
                    printf("SB ");

                else if (packet2 == 0xf9)
                    printf("GA ");

                else if (packet2 == 0xf8)
                    printf("EL ");

                else if (packet2 == 0xf7)
                    printf("EC ");

                else if (packet2 == 0xf6)
                    printf("AYT ");

                else if (packet2 == 0xf5)
                    printf("AO ");

                else if (packet2 == 0xf4)
                    printf("IP ");

                else if (packet2 == 0xf3)
                    printf("BREAK ");

                else if (packet2 == 0xf2)
                    printf("DM ");

                else if (packet2 == 0xf1)
                    printf("NOP ");

                else if (packet2 == 0xf0)
                    printf("SE ");

            } else {
                if (packet2 == 0x00)
                    printf("BINARY \n");
                else if (packet2 == 0x01)
                    printf("ECHO\n");
                else if (packet2 == 0x02)
                    printf("RECONNECTION\n");
                else if (packet2 == 0x03)
                    printf("SUPPRESS GO AHEAD\n");
                else if (packet2 == 0x04)
                    printf("APPROX MESSAGE SIZE NEGOTIATION\n");
                else if (packet2 == 0x05)
                    printf("STATUS\n");
                else if (packet2 == 0x06)
                    printf("TIMING MARK\n");
                else if (packet2 == 0x07)
                    printf("REMOTE CONTROL\n");
                else if (packet2 == 0x08)
                    printf("OUTPUT LINE WIDTH\n");
                else if (packet2 == 0x09)
                    printf("OUTPUT PAGE SIZE\n");
                else if (packet2 == 0x0a)
                    printf("OUTPUT CARAT POSITION\n");
                else if (packet2 == 0x0b)
                    printf("OUTPUT HORIZONTAL TAB STOPS\n");
                else if (packet2 == 0x0c)
                    printf("OUTPUT HORIZONTAL TAB DISPOSITION\n");
                else if (packet2 == 0x0d)
                    printf("OUTPUT FORMFEED DISPOSITION\n");
                else if (packet2 == 0x0e)
                    printf("OUTPUT VERTICAL TAB STOPS\n");
                else if (packet2 == 0x0f)
                    printf("OUTPUT VERTICAL TAB DISPOSITION\n");
                else if (packet2 == 0x10)
                    printf("OUTPUT LINEFEED DISPOSITION\n");
                else if (packet2 == 0x11)
                    printf("EXTENDED ASCII\n");
                else if (packet2 == 0x12)
                    printf("LOGOUT\n");
                else if (packet2 == 0x13)
                    printf("BYTE MACRO\n");
                else if (packet2 == 0x14)
                    printf("DATA ENTRY TERMINAL\n");
                else if (packet2 == 0x15)
                    printf("SUPDUP\n");
                else if (packet2 == 0x16)
                    printf("SUPDUP OUTPUT\n");
                else if (packet2 == 0x17)
                    printf("SEND LOCATION\n");
                else if (packet2 == 0x18)
                    printf("TERMINAL TYPE\n");
                else if (packet2 == 0x19)
                    printf("END OF RECORD\n");
                else if (packet2 == 0x1a)
                    printf("TACACS USER IDENTIFICATION\n");
                else if (packet2 == 0x1b)
                    printf("OUTPUT MARKING\n");
                else if (packet2 == 0x1c)
                    printf("TERMINAL LOCATION NUMBER\n");
                else if (packet2 == 0x1d)
                    printf("TELNET 3270 REGIME\n");
                else if (packet2 == 0x1e)
                    printf("X.3 PAD\n");
                else if (packet2 == 0x1f)
                    printf("NAWS\n");
                else if (packet2 == 0x20)
                    printf("TERMINAL SPEED\n");
                else if (packet2 == 0x21)
                    printf("REMOTE FLOW CONTROL\n");
                else if (packet2 == 0x22)
                    printf("LINEMODE\n");
                else if (packet2 == 0x23)
                    printf("X Display Location\n");
                else if (packet2 == 0x24)
                    printf("Environment Option\n");
                else if (packet2 == 0x25)
                    printf("Authentication Option\n");
                else if (packet2 == 0x26)
                    printf("Encryption Option\n");
                else if (packet2 == 0x27)
                    printf("New Environment Option\n");
                else if (packet2 == 0xff)
                    printf("Extended-Options-List\n");
            }
        }
    } else
        printf("Pas d information TELNET\n");
}