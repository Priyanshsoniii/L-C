#pragma once
#include "../interfaces/IAccount.h"
#include "../exceptions/Exceptions.h"

class Account : public IAccount {
    double balance;
    double dailyLimit;
    double withdrawnToday;

public:
    Account(double initialBalance, double limit)
        : balance(initialBalance), dailyLimit(limit), withdrawnToday(0) {}

    void withdraw(double amount) override {
        if (withdrawnToday + amount > dailyLimit) throw DailyLimitExceededException();
        if (amount > balance) throw InsufficientFundsException();
        balance -= amount;
        withdrawnToday += amount;
    }

    double getBalance() const override { return balance; }

    void resetDailyWithdrawal() override { withdrawnToday = 0; }
};
