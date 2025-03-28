#ifndef PAYMENTPROCESSING_H
#define PAYMENTPROCESSING_H

#include <iostream>
#include <string>

class PaymentProcessing
{
public:
    void makePayment(const std::string &paymentType, double amount, const std::string &cardName, const std::string &cardNumber);
};

#endif
