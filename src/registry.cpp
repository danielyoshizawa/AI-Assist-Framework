#include "registry.h"
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void Registry::SetupRoutes()
{
    json requestData;
    server.Post("/api/register", [this, &requestData](const httplib::Request &req, httplib::Response &res)
    {
        std::cout << "Registry Register CALLED" << std::endl;
        requestData = json::parse(req.body);
        std::string name = requestData["name"];
        std::string address = requestData["address"];
        std::cout << "Registry Register" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Address: " << address << std::endl;
        registerService(name, address);
        res.set_content("Service registered", "application/json");
    });

    server.Post("/api/unregister", [this, &requestData](const httplib::Request &req, httplib::Response &res)
    {
        requestData = json::parse(req.body);
        std::string name = requestData["name"];
        unregisterService(name);
        res.set_content("Service unregistered", "application/json");
    });

    server.Get("/api/get", [this, &requestData](const httplib::Request &req, httplib::Response &res)
    {
        std::cout << "Registry Get" << std::endl;
        std::string name = req.get_param_value("name");
        std::cout << "Name: " << name << std::endl;
        requestData["address"] = services[name];
        std::cout << "Address: " << requestData["address"] << std::endl;
        res.set_content(requestData.dump(), "application/json"); 
    });
}

void Registry::registerService(std::string const &name, std::string const &address)
{
    services[name] = address;
}

void Registry::unregisterService(std::string const &name)
{
    services.erase(name);
}

int main()
{
    Registry registry;
    registry.SetupRoutes();
    registry.Start("registry", 3002);

    return 0;
}