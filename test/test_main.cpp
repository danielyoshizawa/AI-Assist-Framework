#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <httplib.h>

TEST_CASE("Test 1", "[test]") {
    httplib::Client client{"localhost:3000"}; // Service 1
    auto res = client.Get("/api/example");

    REQUIRE(res->body.compare("Hello from the Service 2!\n") == 0);
}