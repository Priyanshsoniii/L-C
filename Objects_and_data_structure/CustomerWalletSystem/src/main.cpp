#include <iostream>
#include "Customer.h"

int main() {
    try {
        Customer customer("Priyansh", "Soni", 100.0f);
        Wallet& wallet = customer.getWallet();
        float payment = 2.00f;
        
        if (wallet.getTotalMoney() > payment) {
            wallet.subtractMoney(payment);
            std::cout << "Payment successful. New balance: " << wallet.getTotalMoney() << std::endl;
        } else {
            std::cout << "Come back later to get my money." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
