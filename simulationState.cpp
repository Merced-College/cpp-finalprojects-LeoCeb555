#include "simulationState.h"
#include "Menu.h"

std::string simulationState::getUserName() const{
    return userName;
};

void simulationState::setUserName(const std::string name){
    userName = name;
};

int simulationState::getCashAmount() const{
    return cashAmount;
};

void simulationState::setCashAmount(const int cash){
    cashAmount = cash;
};

std::string simulationState::getSimulationMode() const{
    return simulationMode;
};

void simulationState::setSimulationMode(const std::string mode){
    simulationMode = mode;
};

void simulationState::setupSimulation(){
    std::string name = Menu::printFirstSequenceAndGetName();
    setUserName(name);
    int cash = Menu::promptForCashAmount();
    setCashAmount(cash);
    std::string mode = Menu::promptForSimulationMode();
    setSimulationMode(mode);
};