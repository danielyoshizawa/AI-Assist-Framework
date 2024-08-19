#include "service.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Service1 : public Service
{
public:
    void SetupRoutes() override
    {
        json requestData;
        server.Get("/api/example", [this, &requestData](const httplib::Request &, httplib::Response &res)
                   {
                    std::cout << "Service1" << std::endl;

                    httplib::Client client{"localhost:3002"};
                    auto res2 = client.Get("/api/get?name=service2");

                    if (res2)
                    {
                        requestData = json::parse(res2->body);
                        std::cout << "Address: " << requestData["address"] << std::endl;
                        httplib::Client client2{requestData["address"]};
                        auto res3 = client2.Get("/api/example");
                        std::cout << "Response: " << res3->body << std::endl;
                        res.set_content(res3->body, "text/plain");
                    }
                    else
                    {
                        std::cout << "Error: " << res2.error() << std::endl;
                    }
        });
    }
};

int main()
{
    Service1 service;
    service.SetupRoutes();
    service.Start("service1", 3000);
    return 0;
}