#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include <utility>

class User{
private:
    std::string userName;
    int cashAmount;
    std::vector<std::pair<std::string, int>> stockInventory; //vector of pairs, pairs hold ticker symbols and amounts
public:
    User(); //default constructor
    User(const std::string name, const int cash); //paramterized constructor, allows for editing of name and cash
    std::string getUserName() const; //accessor for user name
    void setUserName(const std::string name); //mutator for user name
    int getCashAmount() const; //accessor for cash amount
    void setCashAmount(const int cash); //mutator for cash amount
};

#endif