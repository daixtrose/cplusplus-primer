#ifndef IMPL_WITH_INTERFACE_HPP
#define IMPL_WITH_INTERFACE_HPP

// make the inteface defintion visible
#include <polymorphism/i_super_cool_features.hpp>

#include <string>

namespace classic {

class Impl
    : public ISuperCoolFeatures {
private:
    std::string s_ { "<default value>" }; // with default member initializer (C++11)

public:
    std::string coolFeature() const override { return s_; }
    void set(std::string s) override
    {
        s_ = std::move(s);
    }
};

} // namespace modern

#endif // IMPL_WITH_INTERFACE_HPP