#include <gtest/gtest.h>
#include "../DivisorCounter.h"

TEST(DivisorCounterTests, ValidInputsReturnCorrectResult) {
    EXPECT_EQ(DivisorCounter::CountSameDivisorCountPairs(10), 1);
    EXPECT_EQ(DivisorCounter::CountSameDivisorCountPairs(15), 2);
    EXPECT_EQ(DivisorCounter::CountSameDivisorCountPairs(20), 3);
}

TEST(DivisorCounterTests, HandlesNegativeInput) {
    EXPECT_THROW(DivisorCounter::CountSameDivisorCountPairs(-5), std::out_of_range);
    EXPECT_THROW(DivisorCounter::CountSameDivisorCountPairs(-1), std::out_of_range);
}

TEST(DivisorCounterTests, ZeroInput) {
    EXPECT_EQ(DivisorCounter::CountSameDivisorCountPairs(0), 0); 
}