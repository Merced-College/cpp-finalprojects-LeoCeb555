#include "Investment.h"
#include "textTools.h"
#include <iostream>
#include <string>

using textTools::blueTextStart;
using textTools::yellowTextStart;
using textTools::coloredTextEnd;

//Default constructor
Investment::Investment() : investmentName("Unnamed"), investmentPrice(0), investmentPopularity(0.0){}

//Parameterized constructor
Investment::Investment(const std::string& name, const int price, const double popularity)
    : investmentName(name), investmentPrice(price), investmentPopularity(popularity){}

//Accessors
const std::string& Investment::getName() const{
    return investmentName;
}
int Investment::getPrice() const{
    return investmentPrice;
}
double Investment::getPopularity() const{
    return investmentPopularity;
}

//Mutators
void Investment::setName(const std::string& name){
    investmentName= name;
}
void Investment::setPrice(const int price){
    investmentPrice = price;
}
void Investment::setPopularity(const double popularity){
    investmentPopularity = popularity;
}

//Overrides
void Investment::printInfo() const{
    std::cout << blueTextStart << "Name: " << yellowTextStart<< getName() << "\n"
        << blueTextStart << "Price: " << yellowTextStart << "$" << getPrice() << "\n"
        << blueTextStart << "Popularity: " << yellowTextStart << getPopularity()
        << coloredTextEnd << std::endl;
}