#pragma once

class IATMService {
public:
    virtual void withdrawCash(double amount) = 0;
    virtual ~IATMService() = default;
};
