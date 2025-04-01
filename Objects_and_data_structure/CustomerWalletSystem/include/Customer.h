#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <memory>
#include "Wallet.h"

class Customer {
private:
    std::string firstName;
    std::string lastName;
    std::unique_ptr<Wallet> myWallet;

public:
    Customer(std::string first, std::string last, float initialBalance);
    std::string getFirstName() const;
    std::string getLastName() const;
    Wallet& getWallet() const;
};

#endif