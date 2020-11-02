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
    void test_ToStringConvertsToBaseSymbols();
    void test_ToStringConvertsBaseSymbolsQuants();
    void test_ToStringConvertsNumbersWithAddition();
    void test_ToStringConvertsNumbersWithSubstraction();
    void test_ToStringConvertsComplexNumbers();
    void test_ToStringThrowsExceptionIfNumberLargerMaxValue();
    void ToStringBenchmark();

    void test_ToUintConvertsBaseSymbols();
    void test_ToUintConvertsBaseSymbolsQuants();
    void test_ToUintConvertsNumbersWithAddition();
    void test_ToUintConvertsNumbersWithSubstraction();
    void test_ToUintThrowsExceptionIfInputIsEmpty();
    void test_ToUintThrowsExceptionIfInputContainsRepeated5th();
    void test_ToUintThrowsExceptionIfInputContainsSubstractionOf5th();
    void test_ToUintThrowsExceptionIfInputContainsSubstractionOfFarDigits();
    void test_ToUintThrowsExceptionIfInputContainsNonRomanDigitSymbols();
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

void RomanNumbersTest::test_ToStringConvertsToBaseSymbols()
{
    constexpr struct{unsigned int i; const char *const s;} lines[]  = {
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

void RomanNumbersTest::test_ToStringConvertsBaseSymbolsQuants()
{
    constexpr struct{unsigned int i; const char *const s;} lines[]  = {
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

void RomanNumbersTest::test_ToStringConvertsNumbersWithAddition()
{
    constexpr struct{unsigned int i; const char *const s;} lines[]  = {
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

void RomanNumbersTest::test_ToStringConvertsNumbersWithSubstraction()
{
    constexpr struct{unsigned int i; const char *const s;} lines[]  = {
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

void RomanNumbersTest::test_ToStringConvertsComplexNumbers()
{
    constexpr struct{unsigned int i; const char *const s;} lines[]  = {
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

void RomanNumbersTest::test_ToStringThrowsExceptionIfNumberLargerMaxValue()
{
    try {
        auto result = RomanNumbers::toString(RomanNumbers::maxValue + 1);
        QVERIFY(false);
    } catch (...) {
        QVERIFY(true);
    }
}

void RomanNumbersTest::ToStringBenchmark()
{
    QBENCHMARK {
        unsigned int r = std::abs(rand() % RomanNumbers::maxValue + 1);
        RomanNumbers::toString(r);
    }
}

void RomanNumbersTest::test_ToUintConvertsBaseSymbols()
{
    constexpr struct{unsigned int i; const char *const s;} lines[]  = {
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
        auto result = RomanNumbers::toUInt(std::string(line.s));
        QCOMPARE(result, line.i);
    }
}

void RomanNumbersTest::test_ToUintConvertsBaseSymbolsQuants()
{
    constexpr struct{unsigned int i; const char *const s;} lines[]  = {
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
        auto result = RomanNumbers::toUInt(std::string(line.s));
        QCOMPARE(result, line.i);
    }
}

void RomanNumbersTest::test_ToUintConvertsNumbersWithAddition()
{
    constexpr struct{unsigned int i; const char *const s;} lines[]  = {
    {6, "VI"},
    {7, "VII"},
    {8, "VIII"},
    {60, "LX"},
    {80, "LXXX"}
};
    for(auto line : lines)
    {
        auto result = RomanNumbers::toUInt(std::string(line.s));
        QCOMPARE(result, line.i);
    }
}

void RomanNumbersTest::test_ToUintConvertsNumbersWithSubstraction()
{
    constexpr struct{unsigned int i; const char *const s;} lines[]  = {
    {4, "IV"},
    {9, "IX"},
    {40, "XL"},
    {90, "XC"},
    {400, "CD"}
};
    for(auto line : lines)
    {
        auto result = RomanNumbers::toUInt(std::string(line.s));
        QCOMPARE(result, line.i);
    }
}

void RomanNumbersTest::test_ToUintThrowsExceptionIfInputIsEmpty()
{
    try {
        RomanNumbers::toUInt("");
        QVERIFY(false);
    } catch (...) {
        QVERIFY(true);
    }
}

void RomanNumbersTest::test_ToUintThrowsExceptionIfInputContainsRepeated5th()
{
    const char *const lines[] = {
        "VV",
        "LLL",
        "DD"
    };
    for(auto line : lines)
    {
        try {
            RomanNumbers::toUInt(line);
            QVERIFY(false);
        } catch (...) {
            QVERIFY(true);
        }
    }
}

void RomanNumbersTest::test_ToUintThrowsExceptionIfInputContainsSubstractionOf5th()
{
    const char *const lines[] = {
        "VX",
        "LD",
        "DM"
    };
    for(auto line : lines)
    {
        try {
            RomanNumbers::toUInt(line);
            QVERIFY(false);
        } catch (...) {
            QVERIFY(true);
        }
    }
}

void RomanNumbersTest::test_ToUintThrowsExceptionIfInputContainsSubstractionOfFarDigits()
{
    const char *const lines[] = {
        "IL",
        "IC",
        "ID",
        "IM",
        "XD",
        "XM"
    };
    for(auto line : lines)
    {
        try {
            RomanNumbers::toUInt(line);
            QVERIFY(false);
        } catch (...) {
            QVERIFY(true);
        }
    }

}

void RomanNumbersTest::test_ToUintThrowsExceptionIfInputContainsNonRomanDigitSymbols()
{
    const char *const lines[] = {
        "123",
        "CCME",
        "WE"
    };
    for(auto line : lines)
    {
        try {
            RomanNumbers::toUInt(line);
            QVERIFY(false);
        } catch (...) {
            QVERIFY(true);
        }
    }
}

QTEST_APPLESS_MAIN(RomanNumbersTest)

#include "tst_romannumberstest.moc"
