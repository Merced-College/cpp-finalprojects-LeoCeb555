#ifndef STOCKRANKINGS_H
#define STOCKRANKINGS_H
#include "Stock.h"
#include <vector>

class StockRankings{
private:
    std::vector<Stock> stocks;
    std::vector<Stock*> topMovers;
    std::vector<Stock*> mostPopular;
    std::vector<Stock*> stocksToWatch;
public:
    StockRankings();
    StockRankings(std::vector<Stock> stocks);
    std::vector<Stock*> getTopMovers() const;
    std::vector<Stock*> getMostPopular() const;
    std::vector<Stock*> getStocksToWatch() const;
};

#endif