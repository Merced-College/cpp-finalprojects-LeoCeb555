#include "SimulationState.h"
#include <iostream>

std::string SimulationState::getSimulationMode() const{
    return simulationMode;
};

void SimulationState::setSimulationMode(const std::string mode){
    simulationMode = mode;
};

void SimulationState::setupSimulation(User user){
    stocks.loadFromFile("stocks.txt");
    Menu::beginSetupPrompt();
    user.setUserName(Menu::promptForUserName());
    user.setCashAmount(Menu::promptForCashAmount());
    setSimulationMode(Menu::promptForSimulationMode());
    Menu::endSetupPrompt();
};

void SimulationState::runSimulation(User player){
    stocks.loadFromFile("stocks.txt"); //starts stimulation by loading stocks in
    int day = 1; //variable to track days, start on first day
    bool inMainInterface = true, inInvestInterface = false, inSearchInterface = false, 
        inBuyInterface = false, inRankingsInterface = false; //bool flags to track 
        //what menu displays and control flow

    while(day <= 7){ //simulation occurs for seven days 
        if (inMainInterface){ //checks if user is in main menu
            switch(Menu::displayMainInterface()){ //displays main menu and checks user choice
                case 1: //if user selectes button 1 (invest)
                    inMainInterface = false; //sets bool to false (moves to investing menu) and breaks switch
                    inInvestInterface = true;
                    break;
                case 2:
                    //simulateDay() updates stocks with changes
                    day++; //moves to next day and breaks switch
                    break;
                default:
                    break;
            }
        }
        else if(inInvestInterface){ //while not in main menu, checks if user in investing menu
            switch(Menu::displayInvestInterface()){ //displays invest menu and checks user button choice
                case 1: //button 1 is selected (search for stock)
                    inInvestInterface = false; //sets bool flags to false since user
                    inSearchInterface = true;
                    break;
                case 2: //button 2 is selected (buy a stock)
                    inInvestInterface = false; //sets bool flags to false since user is not
                    inBuyInterface = true;
                    break;
                case 3: //button 3 is selected (view full rankings)
                    inInvestInterface = false; //sets bool flags to false since user
                    inRankingsInterface = true;
                    break;
                case 4: //button 4 is selected (go back)
                    inInvestInterface = false; //sets bool flag to false since user is no longer in invest menu
                    inMainInterface = true; //sets bool flag to true since user is now in main menu
                    break;
                default:
                    break;
            }
        }
        else if (inSearchInterface){
            switch(Menu::displaySearchStockInterface()){
            int tracker;
            case 1: //Search by stock ticker symbol
                do{
                    tracker = Menu::displayStockSearchBySymbol(stocks);
                    switch(tracker){
                        case 0:
                            break;
                        case 2:
                            break;
                    }
                }while(tracker == 1);
                break;
            case 2:
                //Search by stock name
                do{
                    tracker = Menu::displayStockSearchByName(stocks);
                    switch(tracker){
                        case 0:
                            break;
                        case 2:
                            break;
                    }
                }while(tracker == 1);
                break;
            case 3:
                //Go back
                inInvestInterface = true;
                inSearchInterface = false;
                break;
            }
        }
    }
};