#include "DivisorCountSieve.h"
#include <stdexcept> 
#include <iostream>  
#include <string>


DivisorCountSieve* DivisorCountSieve::instance = nullptr;

DivisorCountSieve& DivisorCountSieve::getInstance() {
    if (instance == nullptr) {
       
        instance = new DivisorCountSieve();
    }
    return *instance;
}

DivisorCountSieve::DivisorCountSieve() : divisorCounts(MAX_VALUE + 1, 0) {
    
    precomputeDivisorCounts();

}

void DivisorCountSieve::precomputeDivisorCounts() {

    for (int startRange = 1; startRange <= MAX_VALUE; ++startRange) {
        for (int endRange = startRange; endRange <= MAX_VALUE; endRange += startRange) {
            divisorCounts[endRange]++;
        }
    }
}

int DivisorCountSieve::getDivisorCount(int number) const {
    if (number <= 0 || number > MAX_VALUE) {
        throw std::out_of_range("Number " + std::to_string(number) + " is out of precomputed range (1 to " + std::to_string(MAX_VALUE) + ").");
    }
    return divisorCounts[number];
}