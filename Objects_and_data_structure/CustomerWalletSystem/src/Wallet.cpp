#include "Wallet.h"

Wallet::Wallet(float initialBalance) : balance(0.0f) {
    if (initialBalance >= 0) {
        balance = initialBalance;
    } else {
        throw std::invalid_argument("Initial balance cannot be negative");
    }
}

float Wallet::getTotalMoney() const {
    return balance;
}

void Wallet::addMoney(float deposit) {
    if (deposit <= 0) {
        throw std::invalid_argument("Cannot add a negative or zero amount");
    }
    balance += deposit;
}

void Wallet::subtractMoney(float debit) {
    if (debit <= 0) {
        throw std::invalid_argument("Withdrawal amount must be positive");
    }
    if (debit > balance) {
        throw std::runtime_error("Insufficient funds");
    }
    balance -= debit;
}