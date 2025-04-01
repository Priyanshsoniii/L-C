#include <gtest/gtest.h>
#include "Customer.h"

TEST(CustomerTest, WhenGetFirstNameIsCalledThenItreturnCustomerFirstName) {
    Customer customer("Priyansh", "Soni", 100.0f);
    EXPECT_EQ(customer.getFirstName(), "Priyansh");
}

TEST(CustomerTest, WhenGetLastNameIsCalledThenItReturnCustomerLastname){
    Customer customer("Priyansh", "Soni", 100.0f);
    EXPECT_EQ(customer.getLastName(), "Soni");
}

TEST(CustomerTest, WhenGetWalletIsCalledThenItReturnCustomersWallet){
    Customer customer("Priyansh", "Soni", 100.0f);
    Wallet &wallet = customer.getWallet();
    EXPECT_EQ(wallet.getTotalMoney(), 100.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
