// main.cpp
#include <iostream>
#include <vector>
#include "Investment.h"   // Base class
#include "Stock.h" //Derived class

int main() {
    
    Investment appleStock("Apple", 100, 9.2);
    appleStock.getInfo();
    std::cout << std::endl;

    Stock microsoftStock("Microsoft", 200, 9.9, "MSFT", "Tech", 0.3, 0.3);
    microsoftStock.getInfo();



    return 0;
}