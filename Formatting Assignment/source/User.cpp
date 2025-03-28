#include "User.h"

User::User(const std::string &name, const std::string &email) : name(name), email(email) {}

std::string User::getName() const
{
    return name;
}
std::string User::getEmail() const
{
    return email;
}

void User::showInfo() const
{
    std::cout << "User Name: " << name << ", Email: " << email << std::endl;
}
