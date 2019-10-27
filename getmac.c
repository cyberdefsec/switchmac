#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <net/if.h>
#include <sys/unistd.h>
#include <sys/ioctl.h>
#include <net/if_arp.h>

int getmac(char *macaddr, size_t sizebuf, char *dev){
    int sock;
    struct ifreq mac;
    if((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP)) != EOF){
        snprintf(mac.ifr_name, IFNAMSIZ, "%s", dev);
        if(ioctl(sock, SIOCGIFHWADDR, &mac) != EOF){
            snprintf(macaddr, sizebuf, "%.2X:%.2X:%.2X:%.2X:%.2X:%.2X", (u_char)mac.ifr_hwaddr.sa_data[0],
                                                                        (u_char)mac.ifr_hwaddr.sa_data[1],
                                                                        (u_char)mac.ifr_hwaddr.sa_data[2],
                                                                        (u_char)mac.ifr_hwaddr.sa_data[3],
                                                                        (u_char)mac.ifr_hwaddr.sa_data[4],
                                                                        (u_char)mac.ifr_hwaddr.sa_data[5]);
            close(sock);
            return EXIT_SUCCESS;
        }
        else
            close(sock);
    }
    return EOF;
}
