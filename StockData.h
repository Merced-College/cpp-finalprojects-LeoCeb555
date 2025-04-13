#ifndef STOCKDATA_H
#define STOCKDATA_H
#include "Stock.h"
#include <string>
#include <vector>

class StockData{
private:
    std::vector <Stock> stocks; //Vector to store stocks

public:
    //Accessor
    const std::vector<Stock>& getStocks() const;
    //Functions
    bool loadFromFile(const std::string& filename); //To open file and parse stocks into vector
};
#endif