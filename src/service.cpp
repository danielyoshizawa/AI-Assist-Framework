#include "service.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void Service::Start(std::string name, int &&port)
{
    json requestData;
    requestData["name"] = name;
    requestData["address"] = "localhost:" + std::to_string(port);
    std::cout << "Microservice is running on port " << port << std::endl;
    server.Get("/api/health", [this](const httplib::Request &, httplib::Response &res)
               { res.set_content("OK\n", "text/plain"); });

    if (name.compare("registry") != 0)
    {
        httplib::Client client{"localhost:3002"}; // Registry
        auto res = client.Post("/api/register", requestData.dump(), "application/json");
        std::cout << "Request: " << requestData.dump() << std::endl;
        if (res)
        {
            std::cout << "Response: " << res->body << std::endl;
        } else {
            std::cerr << "Error : " << res.error() << std::endl;
        }
    }

    server.listen("localhost", port);
}