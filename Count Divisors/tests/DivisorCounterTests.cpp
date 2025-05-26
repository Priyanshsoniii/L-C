#include <gtest/gtest.h>
#include "../DivisorCounter.h"

TEST(DivisorCounterTests, InputsLessThanThreeShouldReturnZero) {
    EXPECT_EQ(DivisorCounter::CountSameDivisorCountPairs(0), 0);
    EXPECT_EQ(DivisorCounter::CountSameDivisorCountPairs(1), 0);
    EXPECT_EQ(DivisorCounter::CountSameDivisorCountPairs(2), 0);
}

TEST(DivisorCounterTests, ThrowsExceptionForNegativeInput) {
    EXPECT_THROW(DivisorCounter::CountSameDivisorCountPairs(-5), std::out_of_range);
}

TEST(DivisorCounterTests, ValidInputsReturnCorrectResult) {
    EXPECT_EQ(DivisorCounter::CountSameDivisorCountPairs(10), 2);
    EXPECT_EQ(DivisorCounter::CountSameDivisorCountPairs(15), 3);
    EXPECT_EQ(DivisorCounter::CountSameDivisorCountPairs(20), 5);
}

TEST(DivisorCounterTests, LargeInputReturnsPositiveResult) {
    int result = DivisorCounter::CountSameDivisorCountPairs(1000);
    EXPECT_GT(result, 0);
}
