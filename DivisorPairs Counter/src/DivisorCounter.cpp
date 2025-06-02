#include "DivisorCounter.h"
#include <vector>
#include <stdexcept>
#include <cmath> 

void DivisorCounter::ValidateInput(int number) {
    if (number < 0) {
        throw std::out_of_range("Input must be a non-negative integer. Negative numbers are not allowed.");
    }
}

int DivisorCounter::CountSameDivisorCountPairs(int maxInclusiveNumber) {
    ValidateInput(maxInclusiveNumber); 

    if (maxInclusiveNumber < 3) {
        return 0;
    }

    return 0; 
}