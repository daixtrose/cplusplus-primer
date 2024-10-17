#ifndef CONSUME_CLASS_THAT_ADHERES_TO_CONCEPT_IPP
#define CONSUME_CLASS_THAT_ADHERES_TO_CONCEPT_IPP

#include <polymorphism/consume_class_that_adheres_to_concept.hpp>

#include <string>

namespace modern {

// declaration with concept constraint
std::string consume(has_super_cool_features auto& f)
{
    auto answer = "42";
    f.set(answer);
    return "The answer to all questions is " + f.coolFeature();
}

} // namespace modern

#endif // CONSUME_CLASS_THAT_ADHERES_TO_CONCEPT_IPP