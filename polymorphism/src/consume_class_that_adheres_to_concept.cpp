#include <consume_class_that_adheres_to_concept.ipp>
#include <polymorphism/impl_without_interface.hpp>

namespace modern {

// Explicit template instatiation
template std::string consume<Impl>(Impl&);

}
