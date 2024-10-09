#include <example_5/features.hpp>

#include <iostream> // the legacy way to print stuff

int main()
{
    Example e;
    std::cerr << example_5::function_1(e) << '\n';

    return EXIT_SUCCESS;
}