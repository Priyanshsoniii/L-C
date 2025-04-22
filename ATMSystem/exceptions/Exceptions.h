#pragma once
#include <stdexcept>

class ATMException : public std::runtime_error {
public:
    explicit ATMException(const std::string& msg) : std::runtime_error(msg) {}
};

class InsufficientFundsException : public ATMException {
public:
    InsufficientFundsException() : ATMException("Insufficient funds in your account.") {}
};

class InsufficientATMFundsException : public ATMException {
public:
    InsufficientATMFundsException() : ATMException("ATM has insufficient cash.") {}
};

class ServerConnectionException : public ATMException {
public:
    ServerConnectionException() : ATMException("Unable to connect to the server.") {}
};

class InvalidPINException : public ATMException {
public:
    InvalidPINException() : ATMException("Invalid PIN entered.") {}
};

class CardBlockedException : public ATMException {
public:
    CardBlockedException() : ATMException("Card is blocked due to multiple invalid PIN attempts.") {}
};

class DailyLimitExceededException : public ATMException {
public:
    DailyLimitExceededException() : ATMException("Daily withdrawal limit exceeded.") {}
};

class InvalidAmountException : public ATMException {
    public:
        InvalidAmountException() : ATMException("Invalid withdrawal amount. Must be greater than zero.") {}
    };
