#include <QtTest>
#include "../RomanNumbers/RomanNumbers.h"

#include <cstdlib>
#include <ctime>

class RomanNumbersTest : public QObject
{
    Q_OBJECT
public:
    RomanNumbersTest();
    ~RomanNumbersTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_ConvertsToBaseSymbols();
    void test_ConvertsBaseSymbolsQuants();
    void test_ConvertsNumbersWithAddition();
    void test_ConvertsNumbersWithSubstraction();
    void test_ConvertsComplexNumbers();
    void test_ThrowsExceptionIfNumberLargerMaxValue();

    void benchmark();
};

RomanNumbersTest::RomanNumbersTest()
{
    srand(time(0));
}

RomanNumbersTest::~RomanNumbersTest()
{

}

void RomanNumbersTest::initTestCase()
{

}

void RomanNumbersTest::cleanupTestCase()
{

}

void RomanNumbersTest::test_ConvertsToBaseSymbols()
{
    struct{int i; QString s;} lines[]  = {
    {1, "I"},
    {5, "V"},
    {10, "X"},
    {50, "L"},
    {100, "C"},
    {500, "D"},
    {1000, "M"}
};
    for(auto line : lines)
    {
        auto result = RomanNumbers::toString(line.i);
        QCOMPARE(result, line.s);
    }
}

void RomanNumbersTest::test_ConvertsBaseSymbolsQuants()
{
    struct{int i; QString s;} lines[]  = {
    {1, "I"},
    {2, "II"},
    {3, "III"},
    {5, "V"},
    {10, "X"},
    {20, "XX"},
    {30, "XXX"},
    {50, "L"},
    {100, "C"},
    {200, "CC"},
    {300, "CCC"},
    {500, "D"},
    {1000, "M"},
    {2000, "MM"},
    {3000, "MMM"}
};
    for(auto line : lines)
    {
        auto result = RomanNumbers::toString(line.i);
        QCOMPARE(result, line.s);
    }
}

void RomanNumbersTest::test_ConvertsNumbersWithAddition()
{
    struct{int i; QString s;} lines[]  = {
    {6, "VI"},
    {7, "VII"},
    {8, "VIII"},
    {60, "LX"},
    {80, "LXXX"}
};
    for(auto line : lines)
    {
        auto result = RomanNumbers::toString(line.i);
        QCOMPARE(result, line.s);
    }
}

void RomanNumbersTest::test_ConvertsNumbersWithSubstraction()
{
    struct{int i; QString s;} lines[]  = {
    {4, "IV"},
    {9, "IX"},
    {40, "XL"},
    {90, "XC"},
    {400, "CD"}
};
    for(auto line : lines)
    {
        auto result = RomanNumbers::toString(line.i);
        QCOMPARE(result, line.s);
    }
}

void RomanNumbersTest::test_ConvertsComplexNumbers()
{
    struct{int i; QString s;} lines[]  = {
    {4, "IV"},
    {6, "VI"},
    {7, "VII"},
    {8, "VIII"},
    {9, "IX"},
    {40, "XL"},
    {60, "LX"},
    {80, "LXXX"},
    {90, "XC"},
    {400, "CD"},
    {82, "LXXXII"},
    {1900, "MCM"},
    {1988, "MCMLXXXVIII"}
};
    for(auto line : lines)
    {
        auto result = RomanNumbers::toString(line.i);
        QCOMPARE(result, line.s);
    }
}

void RomanNumbersTest::test_ThrowsExceptionIfNumberLargerMaxValue()
{
    try {
        auto result = RomanNumbers::toString(RomanNumbers::maxValue + 1);
        QVERIFY(false);
    } catch (...) {
        QVERIFY(true);
    }
}

void RomanNumbersTest::benchmark()
{
    QBENCHMARK {
        unsigned int r = std::abs(rand() % RomanNumbers::maxValue + 1);
        RomanNumbers::toString(r);
    }
}

QTEST_APPLESS_MAIN(RomanNumbersTest)

#include "tst_romannumberstest.moc"
