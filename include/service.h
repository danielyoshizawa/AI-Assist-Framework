#ifndef SERVICE_H
#define SERVICE_H

#include <httplib.h>

class Service
{
public:
    void Start(std::string name, int && port);

    virtual void SetupRoutes() = 0;

protected:
    httplib::Server server;
};

#endif