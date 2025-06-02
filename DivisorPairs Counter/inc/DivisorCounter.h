#ifndef DIVISOR_COUNTER_H
#define DIVISOR_COUNTER_H

class DivisorCounter {

    private:
    static void ValidateInput(int maxInclusiveNumber);

    public:

    static int CountSameDivisorCountPairs(int maxInclusiveNumber); 
};

#endif