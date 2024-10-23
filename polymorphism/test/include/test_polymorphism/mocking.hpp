#ifndef POLYMORPHISM_MOCKING_HPP
#define POLYMORPHISM_MOCKING_HPP

#include <cstddef>
#include <list>
#include <string>

namespace mocking {

struct Mock {
    std::list<std::string> collectedSetArguments;
    mutable std::size_t numberOfCallsToCoolFeature { 0 };

    std::string coolFeature() const
    {
        ++numberOfCallsToCoolFeature;

        if (0 != collectedSetArguments.size()) {
            return collectedSetArguments.back();
        } else {
            return "<default value>";
        }
    }

    void set(std::string s)
    {
        collectedSetArguments.emplace_back(std::move(s));
    }
};

} // namespace mocking

#endif // POYMORPHISM_MOCKING_HPP