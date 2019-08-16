#include "catch2/catch.hpp"

#include <array>
#include <cstdlib>
#include <limits>

TEST_CASE("Testing memory leak detection") {
    volatile int* array = static_cast<int*>(malloc(sizeof(int) * 100));
    for (int i = 0; i < 100; i++) array[i] = 0;
}

TEST_CASE("Testing buffer overflow detection") {
    std::array<int, 100> global_buffer{};
    int x = global_buffer[500];
    REQUIRE(x == x);
}

TEST_CASE("Testing integer overflow detection") {
    int i = std::numeric_limits<int>::max();
    i += 1;
    REQUIRE((i == i || i > 0));
}
