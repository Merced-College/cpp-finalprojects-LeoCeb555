// main.cpp
#include <iostream>
#include "StockData.h"
#include "SimulationState.h"

int main() {
    User user;
    SimulationState state;
    StockData stocks;
    stocks.loadFromFile("stocks.txt");

    //state.setupSimulation();

    state.setupSimulation(user);
    state.runSimulation(user);

    return 0;
}