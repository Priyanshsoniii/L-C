#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Wallet.h"

class Customer {
private:
    std::string firstName;
    std::string lastName;
    Wallet myWallet;

public:
    Customer(std::string first, std::string last, float initialBalance);

    std::string getFirstName() const;
    std::string getLastName() const;
    
    float getWalletBalance() const;
    bool makePayment(float amount);
    void addFunds(float amount);
};

#endif
