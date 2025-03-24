#include "Wallet.h"

Wallet::Wallet(float initialBalance) : balance(initialBalance) {}

float Wallet::getTotalMoney() const {
    return balance;
}

void Wallet::addMoney(float deposit) {
    balance += deposit;
}

bool Wallet::subtractMoney(float debit) {
    if (debit <= balance) {
        balance -= debit;
        return true;
    }
    return false;
}
