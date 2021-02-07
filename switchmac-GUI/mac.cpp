#include "mac.h"

Mac::Mac(QObject *parent) : QObject(parent){

}

int Mac::shutdownInterface(const QString &nameInterface){
    snprintf(device.ifr_name, IFNAMSIZ - 1, "%s", nameInterface.data());
    if(ioctl(sock, SIOCGIFFLAGS, &device) != EOF){
        if(device.ifr_flags & IFF_UP)
            device.ifr_flags &= ~IFF_UP;
        else
            device.ifr_flags |= IFF_UP;
        if(ioctl(sock, SIOCSIFFLAGS, &device) != EOF)
            return EXIT_SUCCESS;
    }
    return EOF;
}

void Mac::setMacAddress(const QString &nameInetrface, const QString &macAddr){
    if((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP)) != EOF){
        snprintf(device.ifr_name, IFNAMSIZ - 1, "%s", nameInetrface.data());
        device.ifr_hwaddr.sa_family = ARPHRD_ETHER;
        sscanf(macAddr.toLocal8Bit(), "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx", &device.ifr_hwaddr.sa_data[0],
                                                                         &device.ifr_hwaddr.sa_data[1],
                                                                         &device.ifr_hwaddr.sa_data[2],
                                                                         &device.ifr_hwaddr.sa_data[3],
                                                                         &device.ifr_hwaddr.sa_data[4],
                                                                         &device.ifr_hwaddr.sa_data[5]);
        shutdownInterface(nameInetrface);
        if(ioctl(sock, SIOCSIFHWADDR, &device) != EOF){
            shutdownInterface(nameInetrface);
            close(sock);
        }
        close(sock);
    }
}

QString Mac::getMacAddress(const QString &nameInterface){
    foreach(QNetworkInterface interface, QNetworkInterface::allInterfaces()){
        if(interface.name() == nameInterface)
            return interface.hardwareAddress();
    }
    return nullptr;
}

QString Mac::getError(){

}
