#ifndef CONSUME_CLASS_THAT_ADHERES_TO_CONCEPT_HPP
#define CONSUME_CLASS_THAT_ADHERES_TO_CONCEPT_HPP

#include <polymorphism/has_super_cool_features.hpp>

namespace modern {

// declaration with concept constraint
std::string consume(has_super_cool_features auto& s);

} // namespace modern

#endif // CONSUME_CLASS_THAT_ADHERES_TO_CONCEPT_HPP