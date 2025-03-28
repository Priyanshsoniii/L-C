#include "PaymentProcessing.h"

void PaymentProcessing::makePayment(const std::string &paymentType, double amount,
                                    const std::string &cardName, const std::string &cardNumber)
{
    if (paymentType == "Credit")
    {
        std::cout << "Processing Credit Card payment of $" << amount << std::endl;
    }
    else if (paymentType == "Debit")
    {
        std::cout << "Processing Debit Card payment of $" << amount << std::endl;
    }
    else
    {
        std::cout << "Unknown Payment Method" << std::endl;
    }

    if (amount > 1000)
    {
        std::cout << "High-value transaction alert!" << std::endl;
    }

    std::cout << "Payment Done for " << cardName
              << " (Card Ending: " << cardNumber.substr(cardNumber.length() - 4) << ")" << std::endl;
}
