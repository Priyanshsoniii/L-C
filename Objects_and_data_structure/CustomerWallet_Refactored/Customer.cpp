#include "Customer.h"

Customer::Customer(std::string first, std::string last, float initialBalance)
    : firstName(first), lastName(last), myWallet(initialBalance) {}

std::string Customer::getFirstName() const {
    return firstName;
}

std::string Customer::getLastName() const {
    return lastName;
}

float Customer::getWalletBalance() const {
    return myWallet.getTotalMoney();
}

bool Customer::makePayment(float amount) {
    return myWallet.subtractMoney(amount);
}

void Customer::addFunds(float amount) {
    myWallet.addMoney(amount);
}
