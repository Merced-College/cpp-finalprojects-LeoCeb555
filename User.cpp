#include "User.h"

namespace tradingTools{
    int calculateStocksAbleToBuy(int cash, int price){
        return cash / price;
    }
}

User::User() : userName("Unnamed"), cashAmount(0){}

User::User(const std::string& name, const int cash) : userName(name), cashAmount(cash){}

const std::string& User::getUserName() const{
    return userName;
};

void User::setUserName(const std::string& name){
    userName = name;
};

int User::getCashAmount() const{
    return cashAmount;
};

void User::setCashAmount(const int cash){
    cashAmount = cash;
};

void User::addStockShares(const Stock*& stock, int amount){
    for (auto& pair : shareInventory) {
        if (pair.first->getSymbol() == stock->getSymbol()) {
            pair.second += amount;
            return;
        }
    }
    shareInventory.push_back({stock, amount});
}

const std::vector<std::pair<const Stock*, int>>&  User::getUserInventory() const{
    return shareInventory;
}

int User::getShareAmountInInventoryBySymbol(const std::string& symbol) const{
    for (const std::pair<const Stock*, int>& pair : shareInventory){
        if (pair.first->getSymbol() == symbol){
            return pair.second;
        }
    }
    return 0;
}

int User::getShareAmountInInventoryByName(const std::string& name) const{
    for (const std::pair<const Stock*, int>& pair : shareInventory){
        if (pair.first->getName() == name){
            return pair.second;
        }
    }
    return 0;
}

void User::removeStockShares(const std::string& symbol, const int amount){
    for (auto pair = shareInventory.begin(); pair != shareInventory.end(); pair++){
        if (pair->first->getSymbol() == symbol){
            setCashAmount(getCashAmount() + (pair->first->getPrice() * amount));
            if (pair->second == amount){
                shareInventory.erase(pair);
            }
            else{
                pair->second = pair->second - amount;
            }
            return;
        }
    }
}
