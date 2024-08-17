#include "service.h"

void Service::Start(int && port) {
    std::cout << "Microservice is running on port " << port << std::endl;
    server.listen("localhost", port);
}