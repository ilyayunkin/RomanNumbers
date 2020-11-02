#ifndef ROMANNUMBERS_H
#define ROMANNUMBERS_H

#include <string_view>
#include <string>

class RomanNumbers
{
public:
    static constexpr auto maxValue = 3999;
    static std::string toString(const unsigned int n);
    static unsigned int toUInt(const std::string_view &input);
};

#endif // ROMANNUMBERS_H
