#include "RomanNumbers.h"
#include <exception>
#include <algorithm>

namespace  {
constexpr struct{unsigned int value; QChar s;} symbols[] ={
{1000, 'M'},
{500, 'D'},
{100, 'C'},
{50, 'L'},
{10, 'X'},
{5, 'V'},
{1, 'I'}
};
}

QString RomanNumbers::toString(const unsigned int number)
{
    if(number > maxValue)
        throw std::runtime_error("Too large number");

    for(auto it = std::begin(symbols); it != std::end(symbols); ++it)
    {
        if(it->value <= number)
        {
            const auto result = number / it->value;
            return QString().fill(it->s, result)
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
                return QString(left->s) + it->s
                        + toString(number - result);
            }
        }
    }
    return QString();
}
