#ifndef DIVISOR_COUNTER_H
#define DIVISOR_COUNTER_H

#include <vector>

class DivisorCounter {
public:
    static int CountSameDivisorCountPairs(int maxInclusiveNumber);

private:
    static void ValidateInput(int number);
    static std::vector<int> CalculateDivisorCountsUpTo(int maxInclusiveNumber);
};

#endif
