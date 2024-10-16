#ifndef POYMORPHISM_IMPL_WITHOUT_INTERFACE_HPP
#define POYMORPHISM_IMPL_WITHOUT_INTERFACE_HPP

#include <polymorphism/has_super_cool_features.hpp>

#include <string>

namespace modern {

class Impl {
private:
    std::string s_ { "<default value>" }; // with default member initializer (C++11)

public:
    std::string coolFeature() const { return s_; }
    void set(std::string s)
    {
        s_ = std::move(s);
    }
};

// Check if the class adheres to the concept (i.e. has the interface we want it to have).
static_assert(has_super_cool_features<Impl>);

} // namespace modern

#endif // POYMORPHISM_IMPL_WITHOUT_INTERFACE_HPP