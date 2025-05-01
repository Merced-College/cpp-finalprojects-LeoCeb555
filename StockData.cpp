#include "StockData.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

const std::vector<Stock>& StockData::getStocks() const{
    return stocks;
}

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
        int price;
        double popularity, volatility, potential;
        char comma; //For commas

        //If statement seperates line segments into variables and
        //ensures Stock object is only created if all conditions are valid
        if (std::getline(stream, name, ',')  &&(stream >> price >> comma) && (stream >> popularity >> comma) &&
        std::getline(stream, symbol, ',') && std::getline(stream, sector, ',') &&
        (stream >> volatility >> comma >> potential)){

            //emplace_back function constructs Stock based on variables and places it in vector
            stocks.emplace_back(name, price, popularity, symbol, sector, volatility, potential);

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

//CHATGPT
Stock* StockData::getStockBySymbol(const std::string& symbol) {
    auto it = symbolTable.find(symbol);
    
    // Check if the symbol exists in the hash table and the pointer is valid
    if (it != symbolTable.end() && it->second != nullptr) {
        return it->second;
    }

    // If not found, print error and return nullptr
    std::cerr << "[Error] Stock with symbol '" << symbol << "' not found!" << std::endl;
    return nullptr;
}


//FOR TESTING VECTOR OBJECTS
void StockData::printLoadedVectorStocks() const {
    for (const Stock& stock : stocks) {
        std::cout << "Name: " << stock.getName() 
                  << ", Symbol: " << stock.getSymbol()
                  << ", Price: " << stock.getPrice()
                  << ", Sector: " << stock.getSector()
                  << ", Volatilty: " << stock.getVolatility()
                  << ", Potential: " << stock.getPotential() << std::endl;
    }
}

//FOR TESTING HASH TABLE POINTERS
void StockData::printLoadedHashTableStocks() const {
    for (const auto& pair : symbolTable) {
        const std::string& symbol = pair.first;       // Key (stock symbol)
        Stock* stock = pair.second;                   // Value (pointer to Stock)
        
        stock->getInfo();
    }
}