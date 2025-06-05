#include "ProblemSolver.h"
#include<string>

int ProblemSolver::solve(int range) {
    if (range < 3) {
       
        throw std::invalid_argument("Input range must be at least 3 (since 1 < n < range implies n >= 2, so range must be at least 3).");
    }

   
    if (range >= DivisorCountSieve::MAX_VALUE) {
        throw std::out_of_range("Input range (" + std::to_string(range) + ") exceeds the maximum precomputed value of " +
                                 std::to_string(DivisorCountSieve::MAX_VALUE - 1) + " for divisor counts.");
    }

    int count = 0;
   
    DivisorCountSieve& sieve = DivisorCountSieve::getInstance();

  
    for (int currentNumber = 2; currentNumber < range; ++currentNumber) {
       
        int divisorsN = sieve.getDivisorCount(currentNumber);
        int divisorsNPlus1 = sieve.getDivisorCount(currentNumber + 1);

        if (divisorsN == divisorsNPlus1) {
            count++;
        }
    }
    return count;
}