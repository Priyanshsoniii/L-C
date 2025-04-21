#include <iostream>
#include <string>
#include <ctime>
#include "models/Card.h"
#include "models/Account.h"
#include "models/ATM.h"
#include "services/ATMService.h"
#include "exceptions/Exceptions.h"

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Account account(1000.0, 500.0);
    ATM atmMachine(2000.0);
    Card userCard("1234");
    ATMService service(account, atmMachine);

    std::cout << "Welcome to the ATM Simulator\n";

    try {
        std::string enteredPIN;
        while (true) {
            std::cout << "Enter PIN: ";
            std::cin >> enteredPIN;

            try {
                userCard.validatePIN(enteredPIN);
                break;
            } catch (const InvalidPINException& e) {
                std::cerr << e.what() << "\n";
            } catch (const CardBlockedException& e) {
                std::cerr << e.what() << "\n";
                return 1;
            }
        }

        double amount;
        std::cout << "Enter amount to withdraw: ";
        std::cin >> amount;

        try {
            service.withdrawCash(amount);
        } catch (const ATMException& e) {
            std::cerr << "Transaction failed: " << e.what() << "\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << "\n";
    }

    std::cout << "Thank you for using the ATM.\n";
    return 0;
}
