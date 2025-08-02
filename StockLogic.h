#ifndef STOCKRANKINGS_H
#define STOCKRANKINGS_H
#include "StockData.h"

namespace StockLogic{

    //Ranking functions
    std::vector<Stock> rankTopMovers(const StockData data);
    std::vector<Stock> rankMostPopular(const StockData data);
    std::vector<Stock> rankStocksToWatch(const StockData data);
};

#endif