#include <iostream>
#include <string>
#include <thread>
#include "service.h"

int main()
{
    Service service(3000);  // Create service on port 3000
    Service service2(3001); // Create service on port 3001

    std::thread t([&service]()
                  { service.start(); });
    std::thread t2([&service2]()
                   { service2.fetchData(); });
    t.join();
    t2.join();

    return 0;
}