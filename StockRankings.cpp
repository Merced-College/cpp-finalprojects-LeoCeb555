#include "StockRankings.h"
#include <algorithm>

StockRankings::StockRankings(){}
StockRankings::StockRankings(std::vector<Stock> stocks) : stocks(stocks){}

std::vector<Stock*> StockRankings::getTopMovers() const{
    std::sort(stocks.begin(), stocks.end(), [](const Stock& a, const Stock& b)){
        stock.volume
    }
}
std::vector<Stock*> StockRankings::getMostPopular() const{

}
std::vector<Stock*> StockRankings::getStocksToWatch() const{

}