#include "DivisorCounter.h"
#include <vector>
#include <stdexcept>

int DivisorCounter::CountSameDivisorCountPairs(int maxInclusiveNumber) {
    ValidateInput(maxInclusiveNumber);

    if (maxInclusiveNumber < 3) {
        return 0;
    }

    std::vector<int> divisorCounts = CalculateDivisorCountsUpTo(maxInclusiveNumber);
    int consecutiveSameDivisorCountPairs = 0;

    for (int i = 0; i < maxInclusiveNumber - 1; ++i) {
        if (divisorCounts[i] == divisorCounts[i + 1]) {
            ++consecutiveSameDivisorCountPairs;
        }
    }

    return consecutiveSameDivisorCountPairs;
}

void DivisorCounter::ValidateInput(int number) {
    if (number < 0) {
        throw std::out_of_range("Input must be a non-negative integer. Negative numbers are not allowed.");
    }
}

std::vector<int> DivisorCounter::CalculateDivisorCountsUpTo(int maxInclusiveNumber) {
    std::vector<int> divisorCounts(maxInclusiveNumber, 1);  

    for (int divisor = 2; divisor <= maxInclusiveNumber; ++divisor) {
        for (int multiple = divisor; multiple <= maxInclusiveNumber; multiple += divisor) {
            divisorCounts[multiple - 1]++;
        }
    }

    return divisorCounts;
}
