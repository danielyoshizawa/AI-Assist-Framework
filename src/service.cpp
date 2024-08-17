#include "service.h"

Service::Service(int port) : port(port) {
    // Define API endpoint
    server.Get("/api/example", [this](const httplib::Request&, httplib::Response& res) {
        res.set_content("Hello from the microservice!\n", "text/plain");
    });
}

void Service::start() {
    std::cout << "Microservice is running on port " << port << std::endl;
    server.listen("localhost", port);
}

void Service::fetchData() {
    httplib::Client client{"localhost:3000"};
    auto res = client.Get("/api/example");
    std::cout << "Response: " << res->body << std::endl;
}