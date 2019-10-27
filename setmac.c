#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <net/if.h>
#include <sys/unistd.h>
#include <sys/ioctl.h>
#include <net/if_arp.h>
#include <time.h>
#include <stdbool.h>
#include <errno.h>

#include "setmac.h"

static int randoms(void){
    srand(time(NULL));
    return rand() % (255 - 0 + 1);
}

static bool is_mac(char *mac){
    int count = 0;
    while(*mac != '\0'){
        if(*mac == ':')
            count++;
        mac++;
    }
    if(count >= 5)
        return true;
    return false;
}

static int device_shutdown(char *flags, char *dev){
    int sock = 0;
    struct ifreq device;
    if((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP)) != EOF){
        snprintf(device.ifr_name, IFNAMSIZ - 1, "%s", dev);
        if(strcmp(flags, "up") == 0)
            device.ifr_flags |= (IFF_UP | IFF_BROADCAST | IFF_RUNNING | IFF_MULTICAST);
        else if(strcmp(flags, "down") == 0)
            device.ifr_flags &= IFF_UP;
        else{
            close(sock);
            return EOF;
        }
        if(ioctl(sock, SIOCSIFFLAGS, &device) != EOF){
            close(sock);
            return EXIT_SUCCESS;
        }
        close(sock);
    }
    return EOF;
}

int setmac(char *mac, char *dev){
    int sock = 0;
    struct ifreq devmac;
    if((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP)) != EOF){
        snprintf(devmac.ifr_name, IFNAMSIZ - 1, "%s", dev);
        devmac.ifr_hwaddr.sa_family = ARPHRD_ETHER;
        if(is_mac(mac) == false){
            errno = EINVAL;
            close(sock);
            return EOF;
        }
        sscanf(mac, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx", &devmac.ifr_hwaddr.sa_data[0],
                                                     &devmac.ifr_hwaddr.sa_data[1],
                                                     &devmac.ifr_hwaddr.sa_data[2],
                                                     &devmac.ifr_hwaddr.sa_data[3],
                                                     &devmac.ifr_hwaddr.sa_data[4],
                                                     &devmac.ifr_hwaddr.sa_data[5]);

        device_shutdown("down", dev);
        if(ioctl(sock, SIOCSIFHWADDR, &devmac) != EOF){
            device_shutdown("up", dev);
            close(sock);
            return EXIT_SUCCESS;
        }
        close(sock);
    }
    return EOF;
}

int setmac_rand(char *dev){
    int sock = 0;
    int index = 0;
    struct ifreq devmac;
    if((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP)) != EOF){
        snprintf(devmac.ifr_name, IFNAMSIZ - 1, "%s", dev);
        devmac.ifr_hwaddr.sa_family = ARPHRD_ETHER;
        for(index = 0; index < 6; ++index){
            if(index == 0)
                devmac.ifr_hwaddr.sa_data[0] = (randoms() & 254);
            else
                devmac.ifr_hwaddr.sa_data[index] = (randoms() >> index);
        }
        device_shutdown("down", dev);
        if(ioctl(sock, SIOCSIFHWADDR, &devmac) != EOF){
            device_shutdown("up", dev);
            close(sock);
            return EXIT_SUCCESS;
        }
        close(sock);
    }
    return EOF;
}
