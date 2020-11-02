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
constexpr struct{unsigned int value; const char *const s;} symbols2[] ={
{1000, "M"},
{900, "CM"},
{500, "D"},
{400, "CD"},
{100, "C"},
{90, "XC"},
{50, "L"},
{40, "XL"},
{10, "X"},
{9, "IX"},
{5, "V"},
{4, "IV"},
{1, "I"}
};
}

std::string RomanNumbers::toString(const unsigned int number)
{
    if(number > maxValue)
        throw std::runtime_error("Too large number");

    auto n = number;
    std::string ret;
    auto it = std::begin(symbols2);
    while(n)
    {
        if(it->value <= n)
        {
            ret.append(it->s);
            n-= it->value;
        }else{
            ++it;
        }
    }
    return ret;
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
            auto repeatOfNotPowerOfTen = [&previous, &it](){
                return (it->value == previous)
                        && ((previous == 5 )
                            || (previous == 50)
                            || (previous == 500));};
            if(repeatOfNotPowerOfTen())
            {
                throw std::runtime_error("Invalid format");
            }
            if(it->value >= previous)
            {
                ret+= it->value;
            }else
            {
                auto subtractionOfNonPowerOfTen = [&it]{
                    return ((it->value == 5 )
                            || (it->value == 50)
                            || (it->value == 500));};
                if(subtractionOfNonPowerOfTen())
                {
                    throw std::runtime_error("Invalid format");
                }

                auto subtractionOfFarDigit = [&it, &previous]{
                    return (previous != (it - 1)->value)
                            && (previous != (it - 2)->value);};
                if(subtractionOfFarDigit())
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
