#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>

#include "getmac.h"
#include "setmac.h"

void help(void){
    printf("OPTIONS:\n\t");
    printf("-r Random change mac address\n\t");
    printf("-g Get mac address\n\t");
    printf("-m Add mac address\n\t");
    printf("-h Using help\n");
    printf("EXAMPLES:\n\t");
    printf("switchmac -r eth0\n\t");
    printf("switchmac -m 50:2a:14:af:b5:A4 eth0\n");
}

int main(int argc, char **argv){
    int opt = 0;
    opterr = false;
    char macaddr[MAC_SIZE];
    while((opt = getopt(argc, argv, "r:g:m:h")) != EOF){
        switch(opt){
            case 'r' :
                if(getmac(macaddr, MAC_SIZE, argv[2]) != EOF && setmac_rand(argv[2]) != EOF){
                    printf("Current mac address %s: %s\n", argv[2], macaddr);
                    getmac(macaddr, MAC_SIZE, argv[2]);
                    printf("New mac address %s: %s\n", argv[2], macaddr);
                }
                else
                    perror("Set mac");
                return 0;
            case 'm' :
                if(getmac(macaddr, MAC_SIZE, argv[3]) != EOF && setmac(argv[2], argv[3]) != EOF){
                    printf("Current mac address %s: %s\n", argv[3], macaddr);
                    printf("New mac address %s: %s\n", argv[3], argv[2]);
                }
                else
                    perror("Set mac");
                return 0;
            case 'g' :
                if(getmac(macaddr, MAC_SIZE, argv[2]) != EOF)
                    printf("Current mac address %s: %s\n", argv[2], macaddr);
                else
                    perror("Get mac");
                return 0;
            case 'h':
                help();
                return 0;
            default :
                fprintf(stderr, "Invalid argument\n");
                return EOF;
        }
    }
    help();
    return 0;
}
