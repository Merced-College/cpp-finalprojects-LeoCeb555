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

void User::addStockShares(const Stock* stock, int amount){
    stockInventory.push_back({stock, amount});
}

std::vector<std::pair<const Stock*, int>>  User::getStockInventory(){
    return stockInventory;
}

int User::getShareAmountInInventoryBySymbol(std::string symbol){
    for (std::pair<const Stock*, int> pair : stockInventory){
        if (pair.first->getSymbol() == symbol){
            return pair.second;
        }
    }
    return 0;
}

int User::getShareAmountInInventoryByName(std::string name){
    for (std::pair<const Stock*, int> pair : stockInventory){
        if (pair.first->getName() == name){
            return pair.second;
        }
    }
    return 0;
}

void User::removeStockShares(std::string symbol, int amount){
    if (getShareAmountInInventoryBySymbol(symbol) != 0){
        
    }
}