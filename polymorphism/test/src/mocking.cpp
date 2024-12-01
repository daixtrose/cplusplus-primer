#include <consume_class_that_adheres_to_concept.ipp>
#include <test_polymorphism/mocking.hpp>

#include <string>

// explicit instantiation of consume() for Mock
template std::string modern::consume<mocking::Mock>(mocking::Mock&);
