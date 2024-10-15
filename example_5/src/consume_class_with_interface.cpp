#include <example_5/consume_class_with_interface.hpp>

namespace classic {

std::string consume(ISuperCoolFeatures& f)
{
    auto answer = "42";
    f.set(answer);
    return "The answer to all questions is " + f.coolFeature();
}

} // namespace classic