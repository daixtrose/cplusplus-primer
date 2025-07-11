#ifndef POLYMORPHISM_CONSUME_CLASS_THAT_ADHERES_TO_CONCEPT_HPP
#define POLYMORPHISM_CONSUME_CLASS_THAT_ADHERES_TO_CONCEPT_HPP

#include <polymorphism/has_super_cool_features.hpp>

#include <string>

namespace modern {

// declaration with concept constraint
std::string consume(has_super_cool_features auto& s);

} // namespace modern

#endif // POLYMORPHISM_CONSUME_CLASS_THAT_ADHERES_TO_CONCEPT_HPP