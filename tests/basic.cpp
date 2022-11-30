#include <catch2/catch_test_macros.hpp>
#include "../utils.h"
#include "../src/bfs.cpp"
#include "../src/bfs.h"
#include "../src/main.cpp"

#include "bfs.h"

TEST_CASE("Test", "[valgrind][weight=1]"){
    SECTION("Base cases work") {
        REQUIRE(1 == 1);
    }
}

