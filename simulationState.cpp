#include "simulationState.h"

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