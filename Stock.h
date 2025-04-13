#ifndef STOCK_H
#define STOCK_H
#include "Investment.h"
#include <string>
#include <iostream>

class Stock : public Investment{
private:
    std::string symbol;
    std::string sector; // (Tech, Finance, Healthcare, Consumer, Energy, Industrials, Utilities)
    double volatility;
    double potential;

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
    void simulateDay();
};
#endif