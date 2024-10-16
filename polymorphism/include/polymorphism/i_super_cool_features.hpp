#ifndef ISUPERCOOLFEATURES_HPP
#define ISUPERCOOLFEATURES_HPP

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

#endif // ISUPERCOOLFEATURES_HPP