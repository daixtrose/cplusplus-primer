#include "library_1/feature_set_1.hpp"
#include "library_1/feature_set_2.hpp"

#include <iostream> // the leagacy way to print stuff

int main() {
    int i_1 = library_1::function_1(5);

    int i_2 = 0;
    i_2 = library_1::function_2(i_1); 

    std::cout << "i_1 = " << i_1 << std::endl;
    std::cout << "i_2 = " << i_2 << std::endl;
}