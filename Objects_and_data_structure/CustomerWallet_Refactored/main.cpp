#include <iostream>
#include "Customer.h"

int main() {
    Customer myCustomer("John", "Doe", 10.00f); 
    float payment = 2.00f;

    std::cout << "I want my two dollars!\n";

    if (myCustomer.makePayment(payment)) {
        std::cout << "Payment successful!\n";
    } else {
        std::cout << "Come back later and get my money!\n";
    }

    return 0;
}
