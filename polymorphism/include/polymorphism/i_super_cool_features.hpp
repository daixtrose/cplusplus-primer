#ifndef POLYMORPHISM_I_SUPER_COOL_FEATURES_HPP
#define POLYMORPHISM_I_SUPER_COOL_FEATURES_HPP

#include <string>

namespace classic {

/// @brief A typical interface definition via a class with pure virtual functions/methods.
class ISuperCoolFeatures {
public:
    [[nodiscard]] virtual std::string coolFeature() const = 0; // Pure virtual function
    virtual void set(std::string s) = 0; // Pure virtual function
    virtual ~ISuperCoolFeatures() = default; // Virtual destructor
};

} // namespace classic

#endif // POLYMORPHISM_I_SUPER_COOL_FEATURES_HPP