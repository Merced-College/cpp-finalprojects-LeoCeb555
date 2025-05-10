#include "User.h"

User::User() : userName("Unnamed"), cashAmount(0){}

User::User(const std::string name, const int cash) : userName(name), cashAmount(cash){}

std::string User::getUserName() const{
    return userName;
};

void User::setUserName(const std::string name){
    userName = name;
};

int User::getCashAmount() const{
    return cashAmount;
};

void User::setCashAmount(const int cash){
    cashAmount = cash;
};