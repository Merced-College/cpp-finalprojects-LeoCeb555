#include "SimulationState.h"
#include <iostream>

const std::string& SimulationState::getSimulationMode() const{
    return simulationMode;
};

void SimulationState::setSimulationMode(const std::string& mode){
    simulationMode = mode;
};

void SimulationState::setupSimulation(){
    stocks.loadFromFile("stocks.txt"); //starts setup by loading stocks in
    Menu::promptToBeginSetup();
    user.setUserName(Menu::promptForUserName());
    user.setCashAmount(Menu::promptForCashAmount());
    setSimulationMode(Menu::promptForSimulationMode());
    Menu::promptToEndSetup();
};

void SimulationState::runSimulation(){
    int day = 1; //variable to track days, start on first day
    bool inMainInterface = true, inInvestInterface = false, inPortfolioInterface = false,
        inSearchInterface = false, inBuyInterface = false, inSellInterface = false, inRankingsInterface = false; //bool flags to track 
        //what menu displays and control flow

    while(day <= 7){ //simulation occurs for seven days 
        if (inMainInterface){ //checks if user is in main menu
            switch(Menu::displayMainInterface()){ //displays main menu and checks user choice
                case 1: //if user selectes button 1 (invest)
                    inMainInterface = false; //sets bool to false (moves to investing menu) and breaks switch
                    inInvestInterface = true;
                    break;
                case 2:
                    inMainInterface = false;
                    inPortfolioInterface = true;
                    break;
                case 3:
                    //simulateDay() updates stocks with changes
                    day++; //moves to next day and breaks switch
                    //std::cout << "USER CASH: " << user.getCashAmount();
                    break;
                default:
                    break;
            }
        }
        else if(inPortfolioInterface){
            switch(Menu::displayPortfolioInterface(user)){
                case 1:
                    inPortfolioInterface = false;
                    inMainInterface = true;
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
                case 3: //button 3 is selected (sell a stock)
                    inInvestInterface = false;
                    inSellInterface = true;
                    break;
                case 4: //button 4 is selected (view full rankings)
                    inInvestInterface = false; //sets bool flags to false since user
                    inRankingsInterface = true;
                    break;
                case 5: //button 5 is selected (go back)
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
                        tracker = Menu::promptToSearchStockBySymbol(stocks);
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
                        tracker = Menu::promptToSearchStockByName(stocks);
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
        else if(inBuyInterface){
            switch(Menu::displayBuyStockInterface()){
                const Stock* stock;
                int amount;
                case 1: //buy stock by symbol
                    stock = Menu::promptToGetStockUsingSymbol(stocks);
                    if(stock != nullptr){
                        amount = Menu::promptToGetBoughtShares(user.getCashAmount(), stock);
                        if (amount != 0){
                            user.addStockShares(stock, amount);
                            user.setCashAmount(user.getCashAmount() - (stock->getPrice() * amount));
                            //std::cout << "User cash: " << user.getCashAmount();
                        }
                    }
                    break;
                case 2: //buy stock by name
                    stock = Menu::promptToGetStockUsingName(stocks);
                    if(stock != nullptr){
                        amount = Menu::promptToGetBoughtShares(user.getCashAmount(), stock);
                        if (amount != 0){
                            user.addStockShares(stock, amount);
                            user.setCashAmount(user.getCashAmount() - (stock->getPrice() * amount));
                            //std::cout << "User cash: " << user.getCashAmount();
                        }
                    }
                    break;
                case 3:
                    inBuyInterface = false;
                    inInvestInterface = true;
                    break;
            }
        }
        else if(inSellInterface){
            switch(Menu::displaySellStockInterface()){
                const Stock* stock;
                int amount;
                case 1: //sell stock by symbol
                    stock = Menu::promptToGetStockUsingSymbol(stocks);
                    if(stock != nullptr){
                        amount = Menu::promptToGetSoldShares(user.getCashAmount(),
                        user.getShareAmountInInventoryBySymbol(stock->getSymbol()),
                        stock);
                        if (amount != 0){
                            user.removeStockShares(stock->getSymbol(), amount);
                        }
                    }
                    break;
                case 2: //sell stock by name
                    stock = Menu::promptToGetStockUsingName(stocks);
                    if(stock != nullptr){
                        amount = Menu::promptToGetSoldShares(user.getCashAmount(),
                        user.getShareAmountInInventoryBySymbol(stock->getSymbol()), stock);
                        if (amount != 0){
                            user.removeStockShares(stock->getSymbol(), amount);
                            //std::cout << "User cash: " << user.getCashAmount();
                        }
                    }
                    break;
                case 3:
                    inSellInterface = false;
                    inInvestInterface = true;
                    break;
            }
        }
        else if (inRankingsInterface){
            switch(Menu::displayViewRankingsInterface()){
                case 1: //view top movers
                    Menu::printTopMoversMenu(stocks);
                    break;
                case 2: //view most popular
                    Menu::printMostPopularMenu(stocks);
                    break;
                case 3: //view stocks to watch
                    Menu::printStocksToWatchMenu(stocks);
                    break;
                case 4:
                    inRankingsInterface = false;
                    inInvestInterface = true;
                    break;
            }
        }
    }
};