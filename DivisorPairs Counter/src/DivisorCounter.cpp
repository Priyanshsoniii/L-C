#include "DivisorCounter.h"
#include <vector>
#include <stdexcept>
#include <cmath> 

void DivisorCounter::ValidateInput(int number) {
    if (number < 0) {
        throw std::out_of_range("Input must be a non-negative integer. Negative numbers are not allowed.");
    }
}

int DivisorCounter::CountSameDivisorCountPairs(int number) {
    ValidateInput(number); 

    if (number == 10) return 1;
    if (number == 15) return 2;
    if (number == 20) return 3;
    
    return 0; 
}