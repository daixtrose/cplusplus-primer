#ifndef EXAMPLE_5_FEATURES_HPP
#define EXAMPLE_5_FEATURES_HPP

#include <string>

namespace example_5 {

template <typename T>
concept has_super_cool_features = requires(T t) {
    { t.hello() } -> std::convertible_to<std::string>;
};

// declaration with concept constraint
std::string function_1(has_super_cool_features auto const& s);

} // namespace example_5

struct Example {
    std::string hello() const { return "42"; }
};

#endif // EXAMPLE_5_FEATURES_HPP