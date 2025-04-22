#pragma once
class IAccount {
public:
    virtual void withdraw(double amount) = 0;
    virtual double getBalance() const = 0;
    virtual void resetDailyWithdrawal() = 0;
    virtual ~IAccount() = default;
};
