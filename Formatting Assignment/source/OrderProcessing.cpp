#include "OrderProcessing.h"

void OrderProcessing::processOrder(const User& user, const Order& order) {
    double total = order.calculateTotal();
    
    std::string orderDetails = "Item: " + order.getProductName() + ", Qty: " + 
                               std::to_string(order.getProductQuantity()) + ", Total: $" + 
                               std::to_string(total);
    
    orders.push_back(orderDetails);

    std::cout << "Order Placed!\nUser: " << user.getName() 
              << ", Item: " << order.getProductName() 
              << ", Quantity: " << order.getProductQuantity() 
              << ", Total: $" << total << std::endl;

    if (order.getProductQuantity() > 10) {
        std::cout << "Bulk Order Alert!" << std::endl;
    }

    sendEmail(user.getEmail(), "Order placed for " + order.getProductName() + 
                               " with total cost $" + std::to_string(total));
}

void OrderProcessing::sendEmail(const std::string& email, const std::string& message) {
    std::cout << "Sending email to: " << email << " | Message: " << message << std::endl;
}
