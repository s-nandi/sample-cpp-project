#ifndef SAMPLE_CPP_PROJECT_LIBRARY_HPP
#define SAMPLE_CPP_PROJECT_LIBRARY_HPP

#include <string>

namespace sample_cpp_project {
/**
 *
 * A friendly greeter
 */
class greeter {
   public:
    greeter() = default;
    /**
     * Returns a greeting
     */
    auto greet() -> std::string;

   private:
    std::string greeting_{"hello"};
};
}  // namespace sample_cpp_project

#endif  // SAMPLE_CPP_PROJECT_LIBRARY_HPP
