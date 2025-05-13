#include "Stock.h"
#include "Investment.h"
#include "textTools.h"
#include <iostream>
#include <string>

using textTools::blueTextStart;
using textTools::yellowTextStart;
using textTools::coloredTextEnd;

//Default constructor
Stock::Stock() : Investment(), symbol("N/A"), volatility(0.0), potential(0.0) {}

//Parameterized constructor
Stock::Stock(const std::string& name, int price, double popularity, const std::string& symbol,
    const std::string& sector, const double volatility, const double potential) 
    : Investment(name, price, popularity), symbol(symbol), sector(sector), volatility(volatility),
    potential(potential) {}

//Accessors
std::string Stock::getSymbol() const{
    return symbol;
}
std::string Stock::getSector() const{
    return sector;
}
double Stock::getVolatility() const{
    return volatility;
}
double Stock::getPotential() const{
    return potential;
}

//Mutators
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

//Overrides
void Stock::getInfo() const{
    Investment::getInfo();
    std::cout << blueTextStart << "Symbol: " << yellowTextStart << getSymbol() << std::endl;
    std::cout << blueTextStart << "Sector: " << yellowTextStart<< getSector() << std::endl;
    std::cout << blueTextStart << "Volatility: " << yellowTextStart << getVolatility() << std::endl;
    std::cout << blueTextStart << "Potential: " << yellowTextStart << getPotential() << 
    coloredTextEnd << "\n\n";
}

//New functions
void Stock::simulateDay(){

}