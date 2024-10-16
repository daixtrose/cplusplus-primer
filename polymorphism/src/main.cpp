#include <polymorphism/consume_class_that_adheres_to_concept.hpp>
#include <polymorphism/consume_class_with_interface.hpp>
#include <polymorphism/impl_with_interface.hpp>
#include <polymorphism/impl_without_interface.hpp>

#include <iostream> // the legacy way to print stuff

int main()
{
    {
        classic::Impl i;
        std::cerr << classic::consume(i) << '\n';
    }

    {
        modern::Impl i;
        std::cerr << modern::consume(i) << '\n';
    }

    return EXIT_SUCCESS;
}