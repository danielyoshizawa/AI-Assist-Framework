#include <iostream>
#include <string>
#include <httplib.h>  // A simple HTTP library for C++

class Microservice {
private:
    int port;
public:
    Microservice(int port) : port{port} {
        // Define API endpoint
        server.Get("/api/example", [this](const httplib::Request&, httplib::Response& res) {
            res.set_content("Hello from the microservice!\n", "text/plain");
        });
    }

    void start() {
        std::cout << "Microservice is running on port " << port << std::endl;
        server.listen("localhost", port);
    }

private:
    httplib::Server server;  // HTTP server instance
};

int main() {
    Microservice service(3000);  // Create service on port 3000
    service.start();              // Start the service
    return 0;
}