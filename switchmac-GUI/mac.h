#ifndef MAC_H
#define MAC_H

#include <QObject>
#include <QtNetwork/QNetworkInterface>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <net/if.h>
#include <sys/unistd.h>
#include <sys/ioctl.h>
#include <net/if_arp.h>

class Mac : public QObject {

    Q_OBJECT

public:
    Mac(QObject *parent = nullptr);
    virtual ~Mac(){}

private:
    int sock;
    struct ifreq device;
    int shutdownInterface(const QString &nameInterface);

public slots:
    void setMacAddress(const QString &nameInetrface, const QString &macAddr);
    QString getMacAddress(const QString &nameInterface);
    QString getError();

};

#endif // MAC_H
