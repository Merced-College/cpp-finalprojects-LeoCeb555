#include "StockLogic.h"
#include <algorithm>

//Ranking functions
std::vector<Stock> StockLogic::rankTopMovers(const StockData data){ //Rank by most volume
    std::vector<Stock> sortedStocks = data.getStocks();
    std::sort(sortedStocks.begin(), sortedStocks.end(), [](Stock a, Stock b){
        return a.getVolume() > b.getVolume();
    });

    return sortedStocks;
}
std::vector<Stock> StockLogic::rankMostPopular(const StockData data){ //Rank by highest popularity rating
    std::vector<Stock> sortedStocks = data.getStocks();
    std::sort(sortedStocks.begin(), sortedStocks.end(), [](Stock a, Stock b){
        return a.getPopularity() > b.getPopularity();
    });

    return sortedStocks;
}
std::vector<Stock> StockLogic::rankStocksToWatch(const StockData data){ //Rank by highest potential rating
    std::vector<Stock> sortedStocks = data.getStocks();
    std::sort(sortedStocks.begin(), sortedStocks.end(), [](Stock a, Stock b){
        return a.getPotential() > b.getPotential();
    });

    return sortedStocks;
}