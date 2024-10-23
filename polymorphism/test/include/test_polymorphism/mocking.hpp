#ifndef POLYMORPHISM_MOCKING_HPP
#define POLYMORPHISM_MOCKING_HPP

#include <atomic>
#include <cstddef>
#include <list>
#include <string>

namespace mocking {

struct Mock {
    std::list<std::string> collectedSetArguments;
    mutable std::atomic<std::size_t> numberOfCallsToCoolFeature { 0 };

    std::string coolFeature() const
    {
        ++numberOfCallsToCoolFeature;

        return collectedSetArguments.empty()
            ? "<default value>"
            : collectedSetArguments.back();
    }

    /**
     * @brief Stores a string value for later retrieval by coolFeature
     * @param s The string to store (must not be empty)
     * @throws std::invalid_argument if the string is empty
     */
    void set(std::string s)
    {
        if (s.empty()) {
            throw std::invalid_argument("Empty strings are not allowed");
        }
        collectedSetArguments.emplace_back(std::move(s));
    }
};

} // namespace mocking

#endif // POLYMORPHISM_MOCKING_HPP