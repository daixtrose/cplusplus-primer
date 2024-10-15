#ifndef EXAMPLE_5_FEATURES_HPP
#define EXAMPLE_5_FEATURES_HPP

#include <string>

namespace modern {

/// @brief A concept defintion describing a class or struct that has two member functions.
template <typename T>
concept has_super_cool_features = requires(T t, std::string s) {
    { t.coolFeature() } -> std::convertible_to<std::string>;
    { t.set(s) } -> std::same_as<void>;
};

} // namespace modern

#endif // EXAMPLE_5_FEATURES_HPP