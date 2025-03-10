#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User
{
private:
    std::string name;
    std::string email;

public:
    User(const std::string &name, const std::string &email);
    std::string getName() const;
    std::string getEmail() const;
    void showInfo() const;
};

#endif
