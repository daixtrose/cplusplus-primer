#ifndef POLYMORPHISM_IMPL_WITH_INTERFACE_HPP
#define POLYMORPHISM_IMPL_WITH_INTERFACE_HPP

// make the inteface defintion visible
#include <polymorphism/i_super_cool_features.hpp>

#include <string>

namespace classic {

class Impl
    : public ISuperCoolFeatures {
private:
    std::string s_ { "<default value>" }; // with default member initializer (C++11)

public:
    std::string coolFeature() const noexcept override { return s_; }
    void set(std::string s) noexcept override
    {
        s_ = std::move(s);
    }
};

} // namespace classic

#endif // POLYMORPHISM_IMPL_WITH_INTERFACE_HPP