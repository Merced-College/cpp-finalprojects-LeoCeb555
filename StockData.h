#ifndef STOCKDATA_H
#define STOCKDATA_H
#include "Stock.h"
#include <string>
#include <vector>
#include <unordered_map>

//StockData handles the parsing of Stock text file, creation of Stock objects, storing of Stocks, and searching of Stocks
class StockData{
private:
    std::vector <Stock> stocks; //Vector to store stocks
    std::unordered_map<std::string, Stock*> symbolTable; //Hash table to store stocks

public:
    //Accessor
    const std::vector<Stock>& getStocks() const;
    //Functions
    bool loadFromFile(const std::string& filename); //To open file and parse stocks into vector
    const Stock* getStockBySymbol(const std::string& symbol) const; //For efficient searching of stocks by symbol
    const Stock* getStockByName(const std::string& name) const;
    //void printLoadedVectorStocks() const; FOR TESTING
    //void printLoadedHashTableStocks() const; FOR TESTING
    void printStockInfo(const std::string symbol);
    //void modifyStockValuesBySector();
};
#endif