#include <ut.hpp>

#include <polymorphism/consume_class_that_adheres_to_concept.hpp>
#include <polymorphism/consume_class_with_interface.hpp>
#include <polymorphism/impl_with_interface.hpp>
#include <polymorphism/impl_without_interface.hpp>

#include <test_polymorphism/mocking.hpp>

int main()
{
    using namespace boost::ut;
    using namespace boost::ut::bdd;
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

    "[modern]"_test
        = [] {
              given("I have a an implementation that adheres to a concept") = [] {
                  modern::Impl impl;
                  expect("<default value>"s == impl.coolFeature());

                  when("I pass it to a function that expects an argument that fulfils the constraints") = [&] {
                      auto result = modern::consume(impl);

                      then("the answer to all questions should be given") = [=] {
                          expect("The answer to all questions is 42"s == result);
                      };

                      then("the state of the argument should be modified as a side effect") = [=] {
                          expect("42"s == impl.coolFeature());
                      };
                  };
              };
          };

    "[modern mock]"_test = [] {
        static constexpr auto EXPECTED_COOLFEATURE_CALLS = 2; // Called once for initial value and once for modification
        given("I have a an mock that adheres to a concept") = [] {
            mocking::Mock impl;

            expect("<default value>"s == impl.coolFeature());

            when("I pass it to a function that expects an argument that fulfils the constraints") = [&] {
                auto result = modern::consume(impl);

                then("set() should be called twice") = [=] {
                    expect(EXPECTED_COOLFEATURE_CALLS == impl.numberOfCallsToCoolFeature);
                };

                then("the answer to all questions should be given") = [=] {
                    expect("The answer to all questions is 42"s == result);
                };

                then("the state of the argument should be modified as a side effect") = [=] {
                    expect("42"s == impl.coolFeature());
                };
            };
        };
    };
}
