#include "Stock.h"
#include "Investment.h"
#include "textTools.h"
#include <iostream>
#include <string>

using textTools::blueTextStart;
using textTools::yellowTextStart;
using textTools::coloredTextEnd;

//Struct default constructor
StockHistory::StockHistory() : name("N/A"), price(0), popularity(0.0), symbol("N/A"), volatility(0.0), potential(0.0), volume(0) {}

//Struct paramterized constructor
StockHistory::StockHistory(const std::string& name, const int price, const double popularity, const std::string& symbol,
    const std::string& sector, const double volatility, const double potential, const int volume) : name(name), 
    price(price), popularity(popularity), symbol(symbol), volatility(volatility), potential(potential), volume(volume) {}

//Struct accessors
const std::string& StockHistory::getHistoricalName() const{
    return name;
}
int StockHistory::getHistoricalPrice() const{
    return price;
}
double StockHistory::getHistoricalPopularity() const{
    return popularity;
}
const std::string& StockHistory::getHistoricalSymbol() const{
    return symbol;
}
const std::string& StockHistory::getHistoricalSector() const{
    return sector;
}
double StockHistory::getHistoricalVolatility() const{
    return volatility;
}
double StockHistory::getHistoricalPotential() const{
    return potential;
}
int StockHistory::getHistoricalVolume() const{
    return volume;
}

//Struct mutators
void StockHistory::setHistoricalName(const std::string name){
    this->name = name;
}
void StockHistory::setHistoricalPrice(const int price){
    this->price = price;
}
void StockHistory::setHistoricalPopularity(const double popularity){
    this->popularity = popularity;
}
void StockHistory::setHistoricalSymbol(const std::string symbol){
    this->symbol = symbol;
}
void StockHistory::setHistoricalSector(const std::string sector){
    this->sector = sector;
}
void StockHistory::setHistoricalVolatility(const double volatility){
    this->volatility = volatility;
}
void StockHistory::setHistoricalPotential(const double potential){
    this->potential = potential;
}
void StockHistory::setHistoricalVolume(const int volume){
    this->volume = volume;
}

//Class default constructor
Stock::Stock() : Investment(), symbol("N/A"), volatility(0.0), potential(0.0), volume(0) {}

//Class parameterized constructor
Stock::Stock(const std::string& name, int price, double popularity, const std::string& symbol,
    const std::string& sector, const double volatility, const double potential, const int volume) 
    : Investment(name, price, popularity), symbol(symbol), sector(sector), volatility(volatility),
    potential(potential), volume(volume) {}

//Class accessors
const std::string& Stock::getSymbol() const{
    return symbol;
}
const std::string& Stock::getSector() const{
    return sector;
}
double Stock::getVolatility() const{
    return volatility;
}
double Stock::getPotential() const{
    return potential;
}
int Stock::getVolume() const{
    return volume;
}
const std::vector<StockHistory>& Stock::getHistory() const{
    return history;
}

//Class mutators
void Stock::setSymbol(const std::string& symbol){
    this->symbol = symbol;
}
void Stock::setSector(const std::string& sector){
    this->sector = sector;
}
void Stock::setVolatility(const double volatility){
    this->volatility = volatility;
}
void Stock::setPotential(const double potential){
    this->potential = potential;
}
void Stock::setVolume(const int volume){
    this->volume = volume;
}
void Stock::setHistory(const std::vector<StockHistory>& history){
    this->history = history;
}

//Overrides
void Stock::getInfo() const{
    Investment::getInfo();
    std::cout << blueTextStart << "Symbol: " << yellowTextStart << getSymbol() << std::endl;
    std::cout << blueTextStart << "Sector: " << yellowTextStart<< getSector() << std::endl;
    std::cout << blueTextStart << "Volatility: " << yellowTextStart << getVolatility() << std::endl;
    std::cout << blueTextStart << "Potential: " << yellowTextStart << getPotential() << std::endl;
    std::cout << blueTextStart << "Volume: " << yellowTextStart << std::fixed << getVolume() <<
    coloredTextEnd << "\n\n";
}