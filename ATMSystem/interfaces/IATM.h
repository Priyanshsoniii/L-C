#pragma once

class IATM {
public:
    virtual void dispenseCash(double amount) = 0;
    virtual bool simulateServerConnection() const = 0;
    virtual double getCashAvailable() const = 0;
    virtual ~IATM() = default;
};
