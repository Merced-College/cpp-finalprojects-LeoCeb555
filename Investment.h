#ifndef INVESTMENT_H
#define INVESTMENT_H
#include <string>
#include <iostream>

class Investment{
private:
    //Variable to store name of investment
    std::string investmentName;
    //Variable to store price of investment
    int investmentPrice;
    //Variable to store popularity rating of investment
    double investmentPopularity;

public:

    //Default constructor
    Investment();
    //Parameterized constructor
    Investment(const std::string& name, const int price, const double popularity);

    //Accessors
    const std::string& getName() const;
    int getPrice() const;
    double getPopularity() const;

    //Mutators
    void setName(const std::string& name);
    void setPrice(const int price);
    void setPopularity(const double popularity);

    //Overrides

    //Prints investment info
    virtual void getInfo() const;

};

#endif