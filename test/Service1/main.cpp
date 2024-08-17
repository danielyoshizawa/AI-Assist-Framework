#include "service.h"

class Service1 : public Service
{
public:
    void SetupRoutes() override
    {
        server.Get("/api/example", [this](const httplib::Request &, httplib::Response &res)
                   {
                    httplib::Client client{"localhost:3001"};
                    auto res2 = client.Get("/api/example");
                    res.set_content(res2->body, "text/plain"); });
    }
};

int main()
{
    Service1 service;
    service.SetupRoutes();
    service.Start(3000);
    return 0;
}