#include "StockData.h"
#include <iostream>
#include <fstream>
#include <sstream>

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
        if (std::getline(stream, name, ',') &&
        (stream >> price >> comma) && (stream >> popularity >> comma) &&
        std::getline(stream, symbol, ',') && std::getline(stream, sector, ',') &&
        (stream >> volatility >> comma >> potential)){

            //emplace_back function constructs Stock based on variables and places it in vector
            stocks.emplace_back(name, price, popularity, symbol, sector, volatility, potential);

        } else {
            //If 'if' raises flag, prints error message and bad line using cerr
            std::cerr << "Warning: Malformed line: " << line << "\n";
        }
    }
    return true;
}