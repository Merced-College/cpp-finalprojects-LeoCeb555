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

    // Count lines first
    size_t lineCount = std::count(std::istreambuf_iterator<char>(file),
        std::istreambuf_iterator<char>(), '\n');
    file.clear();  // Reset EOF flag
    file.seekg(0); // Rewind to start
    
    stocks.reserve(lineCount);  // Prevent reallocations

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

            std::cout<<name<<std::endl;

            //emplace_back function constructs Stock based on variables and places it in vector
            stocks.emplace_back(name, price, popularity, symbol, sector, volatility, potential);
            //takes the symbol value and uses that as a key for newly inserted stock
            symbolTable[symbol] = &stocks.back();
            //symbolTable[symbol]->getInfo();

        } else {
            //If 'if' raises flag, prints error message and bad line using cerr
            std::cerr << "Warning: Malformed line: " << line << "\n";
        }
    }
    return true;
}

/*
while (getline(file, line)) {
    std::istringstream stream(line);
    std::string name, symbol, sector;
    int price;
    double popularity, volatility, potential;
    char comma;

    // Helper to trim whitespace
    auto trim = [](std::string &s) {
        s.erase(0, s.find_first_not_of(" \t"));
        s.erase(s.find_last_not_of(" \t") + 1);
    };

    // Read name (allows spaces)
    if (!std::getline(stream, name, ',')) {
        std::cerr << "Error: Missing name in line: " << line << "\n";
        continue;
    }
    trim(name);

    // Read price (must be followed by comma)
    if (!(stream >> price >> comma) || comma != ',') {
        std::cerr << "Error: Invalid price/comma in line: " << line << "\n";
        continue;
    }

    // Read popularity (must be followed by comma)
    if (!(stream >> popularity >> comma) || comma != ',') {
        std::cerr << "Error: Invalid popularity/comma in line: " << line << "\n";
        continue;
    }

    // Read symbol (no spaces expected)
    if (!std::getline(stream, symbol, ',')) {
        std::cerr << "Error: Missing symbol in line: " << line << "\n";
        continue;
    }
    trim(symbol);

    // Read sector (allows spaces)
    if (!std::getline(stream, sector, ',')) {
        std::cerr << "Error: Missing sector in line: " << line << "\n";
        continue;
    }
    trim(sector);

    // Read volatility & potential (last field, no trailing comma)
    if (!(stream >> volatility >> comma >> potential) || comma != ',') {
        std::cerr << "Error: Invalid volatility/potential in line: " << line << "\n";
        continue;
    }

    // Success → Add to vector & symbol table
    stocks.emplace_back(name, price, popularity, symbol, sector, volatility, potential);
    symbolTable[symbol] = &stocks.back();
    }
    return true;
}
*/
Stock* StockData::getStockBySymbol(const std::string& symbol){
    auto it = symbolTable.find(symbol);
    if (it != symbolTable.end() && it->second != nullptr) {
        return it->second;
    } else {
        std::cerr << "Stock with symbol " << symbol << " not found!" << std::endl;
        return nullptr;
    }
}

void StockData::printLoadedStocks() const {
    for (const Stock& stock : stocks) {
        std::cout << "Name: " << stock.getName() 
                  << ", Symbol: " << stock.getSymbol()
                  << ", Price: " << stock.getPrice()
                  << ", Sector: " << stock.getSector() << std::endl;
    }
}


void StockData::printLoadedStocks2() const {
    for (const auto& pair : symbolTable) {
        const std::string& symbol = pair.first;       // Key (stock symbol)
        Stock* stock = pair.second;                   // Value (pointer to Stock)
        
        // Use symbol and stock as needed
        // Example:
        std::cout << "Symbol: " << symbol << " ; " << stock->getName()<<std::endl;
        stock->getInfo();
    }
}