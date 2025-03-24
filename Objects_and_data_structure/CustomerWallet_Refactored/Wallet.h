#ifndef WALLET_H
#define WALLET_H

class Wallet {
private:
    float balance;

public:
    Wallet(float initialBalance);

    float getTotalMoney() const;
    void addMoney(float deposit);
    bool subtractMoney(float debit);
};

#endif
