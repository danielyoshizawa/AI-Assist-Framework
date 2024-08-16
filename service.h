#ifndef SERVICE_H
#define SERVICE_H

#include <httplib.h>

class Service
{
public:
    Service(int port);
    void start();
    void fetchData();

private:
    httplib::Server server;
    int port;
};

#endif