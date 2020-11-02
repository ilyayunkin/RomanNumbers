#include "RomanNumbers.h"
#include <stdexcept>
#include <algorithm>

namespace  {
constexpr struct
{
    unsigned int value;
    std::string_view s;
    bool repeatable;
} symbols2[] ={
{1000, "M", true},
{900, "CM", false},
{500, "D", false},
{400, "CD", false},
{100, "C", true},
{90, "XC", false},
{50, "L", false},
{40, "XL", false},
{10, "X", true},
{9, "IX", false},
{5, "V", false},
{4, "IV", false},
{1, "I", true}
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
    auto inputIndex = 0u;
    const auto inputLen = input.length();
    auto it = std::begin(symbols2);
    const auto endIt = std::end(symbols2);
    while(inputIndex < inputLen)
    {
        const auto &symbol = *it;
        const auto substrLen = symbol.s.length();
        const auto substr = input.substr(inputIndex, substrLen);
        if(symbol.s == substr)
        {
            ret+= symbol.value;
            inputIndex+= substrLen;
            if(!symbol.repeatable)
                ++it;
        }else
        {
            ++it;
        }
        if(it == endIt)
            throw std::runtime_error("Invalid format");
    }
    return ret;
}
