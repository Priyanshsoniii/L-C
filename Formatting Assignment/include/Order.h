#ifndef ORDER_H
#define ORDER_H

#include <string>

class Order
{
private:
    std::string productName;
    int quantity;
    double price;

public:
    Order(const std::string &product, int productQuantity, double productPrice);
    double calculateTotal() const;
    std::string getProductName() const;
    int getProductQuantity() const;
};

#endif
