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
    std::vector<std::pair<const Stock*, int>> stockInventory; //vector of pairs, pairs hold ticker symbol and share amount
public:
    User(); //default constructor
    User(const std::string name, const int cash); //paramterized constructor, allows for editing of name and cash
    std::string getUserName() const; //accessor for user name
    void setUserName(const std::string name); //mutator for user name
    int getCashAmount() const; //accessor for cash amount
    void setCashAmount(const int cash); //mutator for cash amount
    void addStockShares(const Stock* stock, int amount);
    std::vector<std::pair<const Stock*, int>> getStockInventory();
    int getShareAmountInInventoryBySymbol(std::string symbol);
    int getShareAmountInInventoryByName(std::string name);
    void removeStockShares(std::string symbol, int amount);

};

#endif