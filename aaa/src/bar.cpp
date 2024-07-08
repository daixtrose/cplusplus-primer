#include "aaa/bar.hpp"

#include <cmath>
#include <numbers>

namespace aaa {

/// @brief Calculates the area of a circle.
/// @param radius
/// @return the area of the circle (π * r²)
double circleArea(double radius)
{
    return std::numbers::pi * std::pow(radius, 2.0);
}

} // namespace aaa
