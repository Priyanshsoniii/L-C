#include "gtest/gtest.h"
#include "DivisorCountSieve.h" 


class DivisorCountSieveTest : public ::testing::Test {
protected:
    
    static DivisorCountSieve& sieve;

    static void SetUpTestSuite() {
        sieve = DivisorCountSieve::getInstance();
    }
};


DivisorCountSieve& DivisorCountSieveTest::sieve = DivisorCountSieve::getInstance();

TEST_F(DivisorCountSieveTest, PrecomputationIsCorrectForSmallNumbers) {

    EXPECT_EQ(sieve.getDivisorCount(1), 1);
    EXPECT_EQ(sieve.getDivisorCount(2), 2); 
    EXPECT_EQ(sieve.getDivisorCount(3), 2);
    EXPECT_EQ(sieve.getDivisorCount(4), 3); 
    EXPECT_EQ(sieve.getDivisorCount(5), 2); 
    EXPECT_EQ(sieve.getDivisorCount(6), 4); 
    EXPECT_EQ(sieve.getDivisorCount(7), 2); 
    EXPECT_EQ(sieve.getDivisorCount(8), 4); 
    EXPECT_EQ(sieve.getDivisorCount(9), 3); 
    EXPECT_EQ(sieve.getDivisorCount(10), 4);
}

TEST_F(DivisorCountSieveTest, PrecomputationMatchesProblemExamples) {
    EXPECT_EQ(sieve.getDivisorCount(14), 4);
    EXPECT_EQ(sieve.getDivisorCount(15), 4); 
}

TEST_F(DivisorCountSieveTest, HandlesPerfectSquaresCorrectly) {
    EXPECT_EQ(sieve.getDivisorCount(25), 3); 
    EXPECT_EQ(sieve.getDivisorCount(36), 9); 
    EXPECT_EQ(sieve.getDivisorCount(49), 3); 
    EXPECT_EQ(sieve.getDivisorCount(100), 9);
}

TEST_F(DivisorCountSieveTest, HandlesLargestPrecomputedValue) {  
    EXPECT_NO_THROW(sieve.getDivisorCount(DivisorCountSieve::MAX_VALUE));
}

TEST_F(DivisorCountSieveTest, ThrowsExceptionForOutOfRangeNumbers) {

    EXPECT_THROW(sieve.getDivisorCount(0), std::out_of_range);
    EXPECT_THROW(sieve.getDivisorCount(-1), std::out_of_range);


    EXPECT_THROW(sieve.getDivisorCount(DivisorCountSieve::MAX_VALUE + 1), std::out_of_range);


    EXPECT_THROW(sieve.getDivisorCount(DivisorCountSieve::MAX_VALUE * 2), std::out_of_range);
}