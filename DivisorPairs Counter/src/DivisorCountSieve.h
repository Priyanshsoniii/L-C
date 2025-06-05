#ifndef DIVISOR_COUNT_SIEVE_H
#define DIVISOR_COUNT_SIEVE_H

#include <vector>
#include <numeric> 

class DivisorCountSieve {
public:
    static const int MAX_VALUE = 10000000 + 1;

    static DivisorCountSieve& getInstance();

    int getDivisorCount(int num) const;

private:

    DivisorCountSieve();
  
    std::vector<int> divisorCounts;

    void precomputeDivisorCounts();

    static DivisorCountSieve* instance;

    DivisorCountSieve(const DivisorCountSieve&) = delete;
    DivisorCountSieve& operator=(const DivisorCountSieve&) = delete;
};

#endif