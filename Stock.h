#ifndef STOCK_H
#define STOCK_H
#include "Investment.h"
#include <string>
#include <vector>
#include <iostream>

struct StockHistory{ //used to track history of individual stock changes
private:
     std::string name;
     int price;
     double popularity;
     std::string symbol;
     std::string sector;
     double volatility;
     double potential;
     int volume;

public:
    //Default constructor
    StockHistory();

    //Parameterized constructor
    StockHistory(const std::string& name, const int price, const double popularity, const std::string& symbol,
        const std::string& sector, const double volatility, const double potential, const int volume);
    
    //Accessors
    const std::string& getHistoricalName() const;
    int getHistoricalPrice() const;
    double getHistoricalPopularity() const;
    const std::string& getHistoricalSymbol() const;
    const std::string& getHistoricalSector() const;
    double getHistoricalVolatility() const;
    double getHistoricalPotential() const;
    int getHistoricalVolume() const;

    //Mutators
    void setHistoricalName(const std::string name);
    void setHistoricalPrice(const int price);
    void setHistoricalPopularity(const double popularity);
    void setHistoricalSymbol(const std::string symbol);
    void setHistoricalSector(const std::string sector);
    void setHistoricalVolatility(const double volatility);
    void setHistoricalPotential(const double potential);
    void setHistoricalVolume(const int volume);

};

//Derived class from base class Investment
//Stock establishes Stock object creation and the manipulation/retrieval of Stock information
class Stock : public Investment{
private:
    std::string symbol; //Used for stock ticker symbol
    std::string sector; /*Used for organization and also affects volatility/potential;
                        Tech, Finance, Healthcare, Consumer, Energy, Industrials, Utilities*/
    double volatility; //Used to determine chances of change
    double potential; //Used to determine what type of change occurs
    int volume; //Used to determine how many shares are being traded which helps determine future outlook
    std::vector<StockHistory> history; //vector that tracks past stock data

public:
    //Default constructor
    Stock();

    //Parameterized constructor
    Stock(const std::string& name, const int price, const double popularity, const std::string& symbol,
        const std::string& sector, const double volatility, const double potential, const int volume);

    //Accessors
    const std::string& getSymbol() const;
    const std::string& getSector() const;
    double getVolatility() const;
    double getPotential() const;
    int getVolume() const;
    const std::vector<StockHistory>& getHistory() const;

    //Mutators
    void setSymbol(const std::string& symbol);
    void setSector(const std::string& sector);
    void setVolatility(const double volatility);
    void setPotential(const double potential);
    void setVolume(const int volume);
    void setHistory(const std::vector<StockHistory>& history);

    //Overrides
    void getInfo() const override;
};
#endif