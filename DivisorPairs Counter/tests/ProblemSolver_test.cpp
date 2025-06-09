#include "gtest/gtest.h"
#include "ProblemSolver.h"     
#include "DivisorCountSieve.h" 


class ProblemSolverTest : public ::testing::Test {
protected:

    static void SetUpTestSuite() {   
        DivisorCountSieve::getInstance();
    }
};

TEST_F(ProblemSolverTest, SampleInputK3) {

    EXPECT_EQ(ProblemSolver::solve(3), 1);
}

TEST_F(ProblemSolverTest, SampleInputK15) {

    EXPECT_EQ(ProblemSolver::solve(15), 2);
}

TEST_F(ProblemSolverTest, SampleInputK100) {

    EXPECT_EQ(ProblemSolver::solve(100), 5);
}

TEST_F(ProblemSolverTest, HandlesMinimumK) {

    EXPECT_NO_THROW(ProblemSolver::solve(3));
    EXPECT_EQ(ProblemSolver::solve(3), 1);
}

TEST_F(ProblemSolverTest, ThrowsExceptionForKLessThan3) {

    EXPECT_THROW(ProblemSolver::solve(0), std::invalid_argument);
    EXPECT_THROW(ProblemSolver::solve(1), std::invalid_argument);
    EXPECT_THROW(ProblemSolver::solve(2), std::invalid_argument);
}

TEST_F(ProblemSolverTest, ThrowsExceptionForKExceedingSieveLimit) {

    EXPECT_THROW(ProblemSolver::solve(DivisorCountSieve::MAX_VALUE + 1), std::out_of_range);
 
    EXPECT_NO_THROW(ProblemSolver::solve(DivisorCountSieve::MAX_VALUE - 1));
}


TEST_F(ProblemSolverTest, CheckKnownMatchesForSpecificRanges) {
   
    EXPECT_EQ(ProblemSolver::solve(1000), 22);
}