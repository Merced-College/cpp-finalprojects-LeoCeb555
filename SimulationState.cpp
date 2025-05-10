#include "SimulationState.h"
#include <iostream>

std::string SimulationState::getSimulationMode() const{
    return simulationMode;
};

void SimulationState::setSimulationMode(const std::string mode){
    simulationMode = mode;
};

void SimulationState::setupSimulation(User user){
    Menu::beginSetupPrompt();
    user.setUserName(Menu::promptForUserName());
    user.setCashAmount(Menu::promptForCashAmount());
    setSimulationMode(Menu::promptForSimulationMode());
    Menu::endSetupPrompt();
};

void SimulationState::runSimulation(User player){
    int day = 1; //start on first
    bool inMainInterface = true; //bool to track what menu is being displayed

    while(day <= 7){ //simulator operates for one week (7 days)
        if (inMainInterface){ //checks if user is in main menu
            switch(Menu::displayMainInterface()){ //checks user choice
                case 1: //if user selectes button 1
                    inMainInterface = false; //sets bool to false (moves to investing menu) and breaks switch
                    break;
                case 2:
                    //simulateDay() updates stocks with changes
                    day++; //moves to next day and breaks switch
                    break;
                default:
                    break;
            }
        }
        else{
            switch(Menu::displayInvestInterface()){ //if not in main menu, displays invest menu
                case 1:
                //Search for stock
                    break;
                case 2:
                //Buy a stock
                    break;
                case 3:
                    //View full rankings
                    break;
                case 4:
                    inMainInterface = true;
                    break;
                default:
                    break;
            }
        }
    }
};