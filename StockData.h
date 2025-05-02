#ifndef STOCKDATA_H
#define STOCKDATA_H
#include "Stock.h"
#include <string>
#include <vector>
#include <unordered_map>

class StockData{
private:
    std::vector <Stock> stocks; //Vector to store stocks
    std::unordered_map<std::string, Stock*> symbolTable; //Hash table to store stocks

public:
    //Accessor
    const std::vector<Stock>& getStocks() const;
    //Functions
    bool loadFromFile(const std::string& filename); //To open file and parse stocks into vector
    Stock* getStockBySymbol(const std::string& symbol); //For efficient searching of stocks by symbol
    //void printLoadedVectorStocks() const; FOR TESTING
    //void printLoadedHashTableStocks() const; FOR TESTING
    void printStockInfo(const std::string symbol);
};
#endif