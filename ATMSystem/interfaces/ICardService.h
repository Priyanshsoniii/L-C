#pragma once
#include <string>

class ICardService {
public:
    virtual void validatePIN(const std::string& enteredPIN) = 0;
    virtual ~ICardService() = default;
};

