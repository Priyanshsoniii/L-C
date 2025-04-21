#pragma once
#include "../interfaces/IATM.h"
#include "../exceptions/Exceptions.h"
#include <cstdlib>

class ATM : public IATM {
    double cashAvailable;

public:
    explicit ATM(double initialCash) : cashAvailable(initialCash) {}

    void dispenseCash(double amount) override {
        if (amount > cashAvailable) throw InsufficientATMFundsException();
        cashAvailable -= amount;
    }

    bool simulateServerConnection() const override {
        return rand() % 10 != 0; // 10% failure chance
    }

    double getCashAvailable() const override {
        return cashAvailable;
    }
};
