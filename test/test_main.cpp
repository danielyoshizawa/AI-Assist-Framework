#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <httplib.h>

TEST_CASE("Test 1", "[test]") {
    httplib::Client client{"localhost:3000"}; // Service 1
    auto res = client.Get("/api/example");

    REQUIRE(res->body.compare("Hello from the Service 2!\n") == 0);
}

TEST_CASE("Health Check", "[test]") {
    httplib::Client client{"localhost:3000"}; // Service 1
    auto res = client.Get("/api/health");

    REQUIRE(res->body.compare("OK\n") == 0);

    httplib::Client client2{"localhost:3001"}; // Service 2
    res = client2.Get("/api/health");

    REQUIRE(res->body.compare("OK\n") == 0);
}