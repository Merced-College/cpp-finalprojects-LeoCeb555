#include "StockData.h"
#include "textTools.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

//Accessors
const std::vector<Stock>& StockData::getStocks() const{
    return stocks;
}

//Mutators
void StockData::setStocks(const std::vector<Stock>& stocks){
    this->stocks = stocks;
}

//Class functions
bool StockData::loadFromFile(const std::string& filename){
    std::ifstream file(filename); //Open file

    //Check if file opened correctly
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl; //Returns error message
        return 1;
        }

    //Parse text files lines into variables and stocks
    std::string line;

    while (getline(file, line)){
        std::istringstream stream(line); //Converts string line to stream
        std::string name, symbol, sector;
        int price, volume;
        double popularity, volatility, potential;
        char comma; //For commas

        //If statement seperates line segments into variables and
        //ensures Stock object is only created if all conditions are valid
        if (std::getline(stream, name, ',')  &&(stream >> price >> comma) && (stream >> popularity >> comma) &&
        std::getline(stream, symbol, ',') && std::getline(stream, sector, ',') &&
        (stream >> volatility >> comma >> potential >> comma) &&(stream >> volume)){

            //emplace_back function constructs Stock based on variables and places it in vector
            stocks.emplace_back(name, price, popularity, symbol, sector, volatility, potential, volume);
            stocks.back().addHistoryRecord(StockHistory(name, price, popularity, symbol, sector, volatility, potential, volume));

        } else {
            //If 'if' raises flag, prints error message and bad line using cerr
            std::cerr << "Warning: Malformed line: " << line << "\n";
        }
        // Step 2: Build the hash table (now safe), iterates through stocks vector and adds it to hash table by symbol
        for (auto& stock : stocks) {
            symbolTable[stock.getSymbol()] = &stock;
        }
    }
    return true;
}

const Stock* StockData::getStockBySymbol(const std::string& symbol) const{ //Function to locate Stock's pointer in hash table
    
    // Check if the symbol exists in the hash table and the pointer is valid
    auto it = symbolTable.find(symbol);  // Single lookup
    return (it != symbolTable.end()) ? it->second : nullptr;
}

const Stock* StockData::getStockByName(const std::string& name) const{
    for (const Stock& stock : getStocks()){
        if ((textTools::makeLowercase(stock.getName())) == (textTools::makeLowercase(name))){
            return &stock;
        }
    }
    return nullptr;
}

void StockData::printStockInfo(const std::string& symbol){
    symbolTable[symbol]->printInfo();
}