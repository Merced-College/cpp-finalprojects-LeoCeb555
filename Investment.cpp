#include "Investment.h"
#include <iostream>
#include <string>

//Default constructor
Investment::Investment() : investmentName("Unnamed"), investmentPrice(0), investmentPopularity(0.0){}

//Parameterized constructor
Investment::Investment(const std::string& name, const int price, const double rating)
    : investmentName(name), investmentPrice(price), investmentPopularity(rating){}

//Accessors
const std::string& Investment::getInvestmentName() const{
    return investmentName;
}
int Investment::getInvestmentPrice() const{
    return investmentPrice;
}
double Investment::getInvestmentPopularity() const{
    return investmentPopularity;
}

//Mutators
void Investment::setName(const std::string& name){
    investmentName= name;
}
void Investment::setInvestmentPrice(const int price){
    investmentPrice = price;
}
void Investment::setInvestmentPopularity(const int rating){
    investmentPopularity = rating;
}

//Overrides