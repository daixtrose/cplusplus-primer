#include <polymorphism/impl_without_interface.hpp>

#include <../src/consume_class_that_adheres_to_concept.ipp>

namespace modern {

// explicit template instatiation
template std::string consume<Impl>(Impl&);

}
