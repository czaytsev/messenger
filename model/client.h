#ifndef CLIENT_H
#define CLIENT_H

#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <QWidget>


class Client : public QWidget
{
    Q_OBJECT

public:
    /**
     * Sets up a TCP connection using socket_
     */
    Client();

    /**
     * Sends a message over the TCP connection
     * @param msg -- a given message
     */
    void send(const std::string &msg);

private:
    int socket_;
};

#endif // CLIENT_H
