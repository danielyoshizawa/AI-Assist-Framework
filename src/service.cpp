#include "service.h"

void Service::Start(int && port) {
    std::cout << "Microservice is running on port " << port << std::endl;
    server.Get("/api/health", [this](const httplib::Request &, httplib::Response &res)
                   { res.set_content("OK\n", "text/plain"); });
    server.listen("localhost", port);
}