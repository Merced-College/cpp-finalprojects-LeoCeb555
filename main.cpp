// main.cpp
#include <iostream>
#include "StockData.h"
#include "Menu.h"
#include "simulationState.h"

int main() {

    simulationState state;
    StockData stocks;
    stocks.loadFromFile("stocks.txt");

    state.setupSimulation();



    return 0;
}