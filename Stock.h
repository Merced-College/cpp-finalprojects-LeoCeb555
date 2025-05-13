#ifndef STOCK_H
#define STOCK_H
#include "Investment.h"
#include <string>
#include <iostream>

//Derived class from base class Investment
//Stock establishes Stock object creation and the manipulation/retrieval of Stock information
class Stock : public Investment{
private:
    std::string symbol; //Used for stock ticker symbol
    std::string sector; /*Used for organization and also affects volatility/potential;
                        Tech, Finance, Healthcare, Consumer, Energy, Industrials, Utilities*/
    double volatility; //Used to determine chances of change
    double potential; //Used to determine what type of change occurs

public:
    //Default constructor
    Stock();

    //Parameterized constructor
    Stock(const std::string& name, const int price, const double popularity, const std::string& symbol,
        const std::string& sector, const double volatility, const double potential);

    //Accessors
    std::string getSymbol() const;
    std::string getSector() const;
    double getVolatility() const;
    double getPotential() const;

    //Mutators
    void setSymbol(const std::string& symbol);
    void setSector(const std::string& sector);
    void setVolatility(const double volatility);
    void setPotential(const double potential);

    //Overrides
    void getInfo() const override;

    //New functions
    void simulateDay(); //Randomly edits stocks based on attributes (meant to represent a month of real life time)
};
#endif