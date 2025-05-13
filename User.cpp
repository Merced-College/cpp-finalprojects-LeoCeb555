#include "User.h"

namespace tradingTools{
    int calculateStocksAbleToBuy(int cash, int price){
        return cash / price;
    }
}

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

void User::addStockShares(std::string name, int amount){
    stockInventory.push_back({name, amount});
}

std::vector<std::pair<std::string, int>>  User::getStockInventory(){
    return stockInventory;
}

std::pair<std::string, int> User::getSpecificStockInInventory(int i){
    return stockInventory.at(i);
}