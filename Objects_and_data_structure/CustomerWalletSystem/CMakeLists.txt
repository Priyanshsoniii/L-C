cmake_minimum_required(VERSION 3.10)
project(CustomerWalletTests)

# Enable testing
enable_testing()

# Set GTest path (Homebrew installs it here)
set(GTEST_ROOT /opt/homebrew/Cellar/googletest/*)
find_package(GTest REQUIRED)

# Include directories
include_directories(${GTEST_INCLUDE_DIRS} include)

# Add Wallet library
add_library(wallet src/Wallet.cpp)
target_include_directories(wallet PUBLIC include)

# Add Customer library
add_library(customer src/Customer.cpp)
target_include_directories(customer PUBLIC include)

# Add Wallet Test
add_executable(WalletTest tests/WalletTest.cpp)
target_link_libraries(WalletTest wallet GTest::GTest GTest::Main pthread)
add_test(NAME WalletTest COMMAND WalletTest)

# Add Customer Test
add_executable(CustomerTest tests/CustomerTest.cpp)
target_link_libraries(CustomerTest customer wallet GTest::GTest GTest::Main pthread)
add_test(NAME CustomerTest COMMAND CustomerTest)
