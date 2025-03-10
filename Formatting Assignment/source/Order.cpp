#include "Order.h"

Order::Order(const std::string &product, int productQuantity, double price)
    : productName(product), quantity(productQuantity), price(price) {}

double Order::calculateTotal() const
{
    double total = quantity * price;
    if (quantity > 5)
        total *= 0.85;

    return total;
}

std::string Order::getProductName() const
{
    return productName;
}
int Order::getProductQuantity() const
{
    return quantity;
}
