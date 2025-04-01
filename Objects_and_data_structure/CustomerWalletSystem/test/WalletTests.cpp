#include <gtest/gtest.h>

#include "Wallet.h"

TEST(WalletTest, WhenGetTotalMoneyIsCalledThenItReturnsWalletBalance) {

    Wallet wallet(50.0f);

    EXPECT_FLOAT_EQ(wallet.getTotalMoney(), 50.0f);

}

TEST(WalletTest, WhenAddMoneyIsCalledThenItReturnsAddedBalance) {

    Wallet wallet(20.0f);

    wallet.addMoney(30.0f);

    EXPECT_FLOAT_EQ(wallet.getTotalMoney(), 50.0f);

}

TEST(WalletTest, WhenSubtractMoneyIsCalledThenItReturnSubtractedBalance) {

    Wallet wallet(50.0f);

    wallet.subtractMoney(20.0f);

    EXPECT_FLOAT_EQ(wallet.getTotalMoney(), 30.0f);

}

TEST(WalletTest, WhenSubtractMoneyWithInsufficientFundsIsCalledThenItThrowsARuntimeException) {

    Wallet wallet(10.0f);

    EXPECT_THROW(wallet.subtractMoney(20.0f), std::runtime_error);

}
 