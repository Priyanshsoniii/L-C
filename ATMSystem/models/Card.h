#pragma once
#include "../interfaces/ICard.h"
#include "../exceptions/Exceptions.h"
#include <string>

class Card : public ICard {
    std::string pin;
    int failedAttempts = 0;
    bool blocked = false;

public:
    explicit Card(std::string correctPIN) : pin(std::move(correctPIN)) {}

    void validatePIN(const std::string& inputPIN) override {
        if (blocked) throw CardBlockedException();
        if (inputPIN != pin) {
            failedAttempts++;
            if (failedAttempts >= 3) {
                blocked = true;
                throw CardBlockedException();
            }
            throw InvalidPINException();
        }
        failedAttempts = 0;
    }

    bool isBlocked() const override {
        return blocked;
    }
};
