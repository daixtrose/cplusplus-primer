#ifndef AAA_FOO_HPP
#define AAA_FOO_HPP

#include <tuple>

namespace aaa {

class Circle {
public:
    /// @brief The representation of a circle.
    /// @param x The position of the midpoint in x-direction.
    /// @param y The position of the midpoint in y-direction.
    /// @param radius The radius of the circle.
    Circle(double x, double y, double radius);

    /// @brief Area
    /// @return The area of the circle
    double getArea();

    /// @brief Midpoint
    /// @return The position of the midpoint of the circle.
    std::tuple<double, double> getPositionOfMidpoint();

private:
    double x_;
    double y_;
    double radius_;
};

} // namespace aaa

#endif // AAA_FOO_HPP