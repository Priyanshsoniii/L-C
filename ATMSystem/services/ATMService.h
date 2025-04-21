#pragma once
#include "../interfaces/IATMService.h"
#include "../interfaces/IAccount.h"
#include "../interfaces/IATM.h"
#include "../exceptions/Exceptions.h"
#include <iostream>

class ATMService : public IATMService {
    IAccount& account;
    IATM& atm;

public:
    ATMService(IAccount& acc, IATM& atmMachine) : account(acc), atm(atmMachine) {}

    void withdrawCash(double amount) override {
        if (!atm.simulateServerConnection()) throw ServerConnectionException();

        account.withdraw(amount);
        atm.dispenseCash(amount);

        std::cout << "Withdrawal successful. Amount: $" << amount << "\n";
        std::cout << "Remaining Balance: $" << account.getBalance() << "\n";
    }
};
