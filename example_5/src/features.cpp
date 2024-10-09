#include <example_5/features.hpp>

namespace example_5 {

std::string function_1(has_super_cool_features auto const& s)
{
    return s.hello();
}

// explicit template instatiation
template std::string function_1<Example>(Example const&);

} // namespace example_5
