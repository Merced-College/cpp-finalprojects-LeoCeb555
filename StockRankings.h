#ifndef STOCKRANKINGS_H
#define STOCKRANKINGS_H
#include "StockData.h"

class StockRankings{
private:
    StockData* baseStocks;
    std::vector<Stock*> topMovers;
    std::vector<Stock*> mostPopular;
    std::vector<Stock*> stocksToWatch;
public:
    StockRankings(StockData* stocks);
    void updateRankings();
    std::vector<Stock*> getTopMovers();
    std::vector<Stock*> getMostPopular();
    std::vector<Stock*> getStocksToWatch();
};

#endif