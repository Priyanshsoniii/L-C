#include "Customer.h"

Customer::Customer(std::string first, std::string last, float initialBalance)
    : firstName(std::move(first)), lastName(std::move(last)), myWallet(std::make_unique<Wallet>(initialBalance)) {}

std::string Customer::getFirstName() const {
    return firstName;
}

std::string Customer::getLastName() const {
    return lastName;
}

Wallet& Customer::getWallet() const {
    return *myWallet;
}