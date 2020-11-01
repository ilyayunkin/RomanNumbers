#ifndef ROMANNUMBERS_H
#define ROMANNUMBERS_H

#include <QString>
class RomanNumbers
{
public:
    static constexpr auto maxValue = 3999;
    static QString toString(const unsigned int n);
};

#endif // ROMANNUMBERS_H
