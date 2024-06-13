#ifndef EXAMPLE_1_FUNCTION_1_HPP
#define EXAMPLE_1_FUNCTION_1_HPP

namespace example_1 {

// declaration and definition in one shot.
// "inline" keyword hinders duplicate definition when this header is included
// more than once
inline int function_1(int arg)
{
    return arg;
}

} // namespace example_1

#endif // EXAMPLE_1_FUNCTION_1_HPP