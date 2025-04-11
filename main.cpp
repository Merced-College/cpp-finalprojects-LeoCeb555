// main.cpp
#include <iostream>
#include <vector>
#include "Investment.h"   // Base class

int main() {
    
    Investment appleStock("Apple", 100, 9.2);
    std::cout << appleStock.getInvestmentName();

    return 0;
}