#include "aaa/foo.hpp"
#include "aaa/bar.hpp"

namespace aaa {

Circle::Circle(double x, double y, double radius)
    : x_ { x }
    , y_ { y }
    , radius_ { radius }
{
    // nothing to be done in this function body
}

double Circle::getArea()
{
    return aaa::circleArea(radius_);
}

std::tuple<double, double> Circle::getPositionOfMidpoint()
{
    return std::make_tuple(x_, y_);
}

} // namespace aaa
