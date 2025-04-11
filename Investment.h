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
    Investment(const std::string& name, const int price, const double rating);

    //Accessors
    const std::string& getInvestmentName() const;
    int getInvestmentPrice() const;
    double getInvestmentPopularity() const;

    //Mutators
    void setName(const std::string& name);
    void setInvestmentPrice(const int price);
    void setInvestmentPopularity(const int rating);

    //Overrides

};

#endif