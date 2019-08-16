#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch2/catch.hpp"

#include "sample_cpp_project/library.hpp"

auto return_hello() -> std::string { return "hello"; }

TEST_CASE("Benchmarking greeter") {
    auto greeter = sample_cpp_project::greeter{};
    BENCHMARK("Using greeter") { greeter.greet(); };
    BENCHMARK("Returning hello") { return_hello(); };
}
