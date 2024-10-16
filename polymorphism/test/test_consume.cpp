#include <ut.hpp>

#include <polymorphism/consume_class_that_adheres_to_concept.hpp>
#include <polymorphism/consume_class_with_interface.hpp>
#include <polymorphism/impl_with_interface.hpp>
#include <polymorphism/impl_without_interface.hpp>

// ctest --rerun-failed --output-on-failure

int main()
{
    using namespace boost::ut;
    using namespace std::string_literals;

    "classic interface call yields 42"_test = [] {
        classic::Impl i;
        expect("<default value>"s == i.coolFeature());
        expect("The answer to all questions is 42"s == classic::consume(i));
    };

    "modern interface call yields 42"_test = [] {
        modern::Impl i;
        expect("<default value>"s == i.coolFeature());
        expect("The answer to all questions is 42"s == modern::consume(i));
        expect("42"s == i.coolFeature());
    };
}
