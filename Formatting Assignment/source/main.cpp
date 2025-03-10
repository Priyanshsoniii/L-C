#include "User.h"
#include "OrderProcessing.h"
#include "PaymentProcessing.h"

int main()
{

    User user("John", "john@example.com");

    OrderProcessing orderProcessor;

    Order order("Laptop", 3, 700.0);
    orderProcessor.processOrder(user, order);

    PaymentProcessing paymentProcessor;
    paymentProcessor.makePayment("Credit", order.calculateTotal(), "John Doe", "1234567890123456");

    return 0;
}
