#ifndef ORDERPROCESSING_H
#define ORDERPROCESSING_H

#include <iostream>
#include <vector>
#include "User.h"
#include "Order.h"

class OrderProcessing
{
private:
    std::vector<std::string> orders;

public:
    void processOrder(const User &user, const Order &order);
    void sendEmail(const std::string &email, const std::string &message);
};

#endif
