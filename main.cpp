// main.cpp
#include <iostream>
#include "StockData.h"
#include "Menu.h"
#include "simulationState.h"

int main() {

    simulationState state;
    StockData stocks;
    stocks.loadFromFile("stocks.txt");

    std::string string = Menu::printFirstSequenceAndGetName(); //
    state.setUserName(string);
    std::cout << state.getUserName();



    return 0;
}