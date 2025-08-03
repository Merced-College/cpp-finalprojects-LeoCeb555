#ifndef STOCKRANKINGS_H
#define STOCKRANKINGS_H
#include "StockData.h"

namespace StockLogic{

    //Updating stocks functions
    std::vector<Stock> simulateStockUpdates(const StockData& data); //simulates stock manipulation for all stocks

    //Ranking stocks functions
    std::vector<Stock> rankTopMovers(const StockData& data); //returns stock vector by most volume in descending order
    std::vector<Stock> rankMostPopular(const StockData& data); //returns stock vector by most popular in descending order
    std::vector<Stock> rankStocksToWatch(const StockData& data); //returns stock vector by most potential in descending order
};

#endif