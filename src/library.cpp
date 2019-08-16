#include "sample_cpp_project/library.hpp"
#include <string>
#include <utility>

namespace sample_cpp_project {

auto greeter::greet() -> std::string { return greeting_; }

}  // namespace sample_cpp_project
