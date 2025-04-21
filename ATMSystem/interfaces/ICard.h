#pragma once
#include <string>

class ICard {
public:
    virtual void validatePIN(const std::string& inputPIN) = 0;
    virtual bool isBlocked() const = 0;
    virtual ~ICard() = default;
};
