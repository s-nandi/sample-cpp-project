#include "catch2/catch.hpp"

#include "sample_cpp_project/library.hpp"

TEST_CASE("Testing greeter::greet") {
    auto greeter = sample_cpp_project::greeter{};
    CHECK(greeter.greet() == "hello");
}
