#ifndef WALLET_H
#define WALLET_H

#include <iostream>
#include <stdexcept>

class Wallet {
private:
    float balance;

public:
    explicit Wallet(float initialBalance);
    float getTotalMoney() const;
    void addMoney(float deposit);
    void subtractMoney(float debit);
};

#endif