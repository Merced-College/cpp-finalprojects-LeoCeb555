// main.cpp
#include <iostream>
#include <vector>
#include "Investment.h"   // Base class
#include "Stock.h" //Derived class
#include "StockData.h"

int main() {
    
    /*Investment appleStock("Apple", 100, 9.2);
    appleStock.getInfo();
    std::cout << std::endl;

    Stock microsoftStock("Microsoft", 200, 9.9, "MSFT", "Tech", 0.3, 0.3);
    microsoftStock.getInfo();*/

    StockData stocks;
    stocks.loadFromFile("stocks.txt");

    /*
    for (const auto& stock : stocks.getStocks()) {
        std::cout << stock.getName() << ": $" << stock.getPrice() << std::endl;
    }*/

    //stocks.getStocks()[0].getInfo();

    //Stock* stock = stocks.getStockBySymbol("TSLA");
    
    //stocks.printLoadedHashTableStocks();
    //std::cout << ";";
    //std::cout << stocks.getStockBySymbol("MSFT")->getName() << std::endl;
    //stocks.getStockBySymbol("MSFT")->getInfo();
    //std::cout << ";";

    /*if (Stock* intcStock = stocks.getStockBySymbol("INTC")) {
        std::cout << "Found INTC stock!" << std::endl;
        intcStock->getInfo();
    } else {
        std::cerr << "INTC stock not found in symbol table!" << std::endl;
    }*/

    //stocks.getStockBySymbol("MS")->getInfo();

    return 0;
}