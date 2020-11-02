#include "RomanNumbers.h"
#include <stdexcept>
#include <algorithm>

namespace  {
constexpr struct{unsigned int value; char s;} symbols[] ={
{1000, 'M'},
{500, 'D'},
{100, 'C'},
{50, 'L'},
{10, 'X'},
{5, 'V'},
{1, 'I'}
};
}

std::string RomanNumbers::toString(const unsigned int number)
{
    if(number > maxValue)
        throw std::runtime_error("Too large number");

    for(auto it = std::begin(symbols); it != std::end(symbols); ++it)
    {
        if(it->value <= number)
        {
            const auto result = number / it->value;
            return std::string(result, it->s)
                    + toString(number % it->value);
        }else if(it->value != 1)
        {
            const auto left =
                    ((it->value == 5 )
                     || (it->value == 50)
                     || (it->value == 500))
                    ? (it + 1)
                    : (it + 2);
            const auto result = it->value - left->value;
            if(result <= number)
            {
                return std::string(1, left->s) + it->s
                        + toString(number - result);
            }
        }
    }
    return std::string();
}

unsigned int RomanNumbers::toUInt(const std::string_view &input)
{
    if(input.empty())
        throw std::runtime_error("Empty input");

    unsigned int ret = 0;
    auto previous = 1u;
    for(auto inputIt = std::rbegin(input); inputIt != std::rend(input); ++inputIt)
    {
        const auto it = std::find_if(std::begin(symbols), std::end(symbols),
                                     [&inputIt](const auto &d){return *inputIt == d.s;});
        if(it != std::end(symbols))
        {
            if((it->value == previous) && ((previous == 5 )
                                           || (previous == 50)
                                           || (previous == 500)))
            {
                throw std::runtime_error("Invalid format");
            }
            if(it->value >= previous)
            {
                ret+= it->value;
            }else
            {
                if(((it->value == 5 )
                    || (it->value == 50)
                    || (it->value == 500)))
                {
                    throw std::runtime_error("Invalid format");
                }
                if((previous != (it - 1)->value)
                        && (previous != (it - 2)->value))
                {
                    throw std::runtime_error("Invalid format");
                }

                ret-= it->value;
            }
            previous = it->value;
        }else
            throw std::runtime_error("Invalid symbol");
    }
    return ret;
}
