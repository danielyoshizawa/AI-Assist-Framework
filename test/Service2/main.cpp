#include "service.h"

class Service2 : public Service
{
public:
    void SetupRoutes() override
    {
        server.Get("/api/example", [this](const httplib::Request &, httplib::Response &res)
                   { res.set_content("Hello from the Service 2!\n", "text/plain"); });
    }
};

int main()
{
    Service2 service;
    service.SetupRoutes();
    service.Start("service2", 3001);
    return 0;
}