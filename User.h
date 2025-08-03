#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include "Stock.h"

//User establishes creation of User object and manipulation/retrieval of User information
namespace tradingTools{ //User object not needed to call function
    int calculateStocksAbleToBuy(int cash, int price);
}

class User{
private:
    std::string userName;
    int cashAmount;
    std::vector<std::pair<const Stock*, int>> stockInventory; //vector of pairs, pairs hold stock pointer and share amount
public:
    User(); //default constructor
    User(const std::string& name, const int cash); //paramterized constructor, allows for editing of name and cash
    const std::string& getUserName() const; //accessor for user name
    void setUserName(const std::string& name); //mutator for user name
    int getCashAmount() const; //accessor for cash amount
    void setCashAmount(const int cash); //mutator for cash amount
    void addStockShares(const Stock*& stock, int amount);
    const std::vector<std::pair<const Stock*, int>>& getStockInventory() const;
    int getShareAmountInInventoryBySymbol(const std::string& symbol) const;
    int getShareAmountInInventoryByName(const std::string& name) const;
    void removeStockShares(const std::string& symbol, const int amount);

};

#endif