#include <iostream>
#include <string>
#include <thread>
#include <httplib.h>

int main()
{
    httplib::Client client{"localhost:3000"}; // Service 1
    auto res = client.Get("/api/example");
    std::cout << "Response: " << res->body << std::endl;

    return 0;
}