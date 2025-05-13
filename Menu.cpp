#include "textTools.h"
#include "Menu.h"
#include "User.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <limits>

using textTools::blueTextStart;
using textTools::redTextStart;
using textTools::greenTextStart;
using textTools::yellowTextStart;
using textTools::coloredTextEnd;


const std::string Menu::Menu::getAction(int i) const{
    return actions.at(i);
}

const std::string Menu::Menu::getPosition(int i) const{
    return positions.at(i);
}

void Menu::Menu::addButton(std::string position, std::string action){
    positions.push_back("[" + position + "] ");
    actions.push_back(action);
}

void Menu::Menu::printButton(int i){
    std::cout << std::endl << blueTextStart << positions[i - 1] << actions[i - 1] << std::endl;
}

void Menu::Menu::printAllButtons(){
    for (int i = 1; i <= positions.size(); ++i){
        printButton(i);
    }
    std::cout << coloredTextEnd << std::endl;
}


//START OF NAMESPACE FUNCTIONS

void Menu::printCashMenu(){
    Menu cashMenu;
    cashMenu.addButton("1", "$100");
    cashMenu.addButton("2", "$1000");
    cashMenu.addButton("3", "$10000");
    cashMenu.addButton("4", "$100000");
    cashMenu.addButton("5", "$1000000");

    std::cout << "What an absolutely magnificent name that is. Now, let's get into your finances." <<
        " How much " << blueTextStart << "cash" << coloredTextEnd << " are you starting with?\n";

    cashMenu.printAllButtons();
}

void Menu::printGameModeMenu(){
    Menu gameModeMenu;
    gameModeMenu.addButton("1", "Realistic");
    gameModeMenu.addButton("2", "Arcade (UNDER CONSTRUCTION)");
    gameModeMenu.addButton("3", "Sandbox (UNDER CONSTRUCTION)");

    std::cout << "Great, now here comes to fun part! What " << blueTextStart 
        << "mode" << coloredTextEnd << " do you want to use?\n\n";

    gameModeMenu.printAllButtons();
}

void Menu::printMainMenu(){
    Menu mainMenu;
    mainMenu.addButton("1", "Invest");
    mainMenu.addButton("2", "View portfolio");
    mainMenu.addButton("3", "Simulate day");

    std::cout << greenTextStart << "StockSim: None of the Risk, All of the Fun\n\n" << 
    yellowTextStart << "What would you like to do?\n";

    mainMenu.printAllButtons();
}

void Menu::printInvestMenu(){
    Menu investMenu;
    investMenu.addButton("1", "Search for Stock");
    investMenu.addButton("2", "Buy a Stock");
    investMenu.addButton("3", "View full rankings (UNDER CONSTRUCTION)");
    investMenu.addButton("4", "Go back");

    std::cout << yellowTextStart << "TOP MOVERS TODAY: (UNDER CONSTRUCTION)\n\n" << redTextStart
    << yellowTextStart << "What would you like to do?\n";

    investMenu.printAllButtons();
}

void Menu::printPortfolioMenu(User user){
    Menu portfolioMenu;
    portfolioMenu.addButton("1", "Go back");

    std::cout << redTextStart << "User: " << yellowTextStart << user.getUserName() 
    << redTextStart << "\nCash Amount: " << yellowTextStart << "$" << user.getCashAmount() << "\n";

    printStockInventory(user);
    portfolioMenu.printAllButtons();
}

void Menu::printSearchStockMenu(){
    Menu searchStockMenu;
    searchStockMenu.addButton("1", "Search Stock by Ticker Symbol");
    searchStockMenu.addButton("2", "Search Stock by Name");
    searchStockMenu.addButton("3", "Go back");

    std::cout << "Would you like to search using a " << greenTextStart << "ticker symbol"
        << coloredTextEnd << " or " << greenTextStart << "name" << coloredTextEnd << "?\n";

    searchStockMenu.printAllButtons();
}

void Menu::printSearchStockErrorMenu(){
    Menu searchStockErrorMenu;
    searchStockErrorMenu.addButton("1", "Try again");
    searchStockErrorMenu.addButton("2", "Go back");

    searchStockErrorMenu.printAllButtons();
}

void Menu::printBuyStockMenu(){
    Menu buyStockMenu;
    buyStockMenu.addButton("1", "Buy Stock by Ticker Symbol");
    buyStockMenu.addButton("2", "Buy Stock by Name");
    buyStockMenu.addButton("3", "Go back");

    std::cout << "Would you like to buy using a " << greenTextStart << "ticker symbol"
        << coloredTextEnd << " or " << greenTextStart << "name" << coloredTextEnd << "?\n";

    buyStockMenu.printAllButtons();
}

void Menu::printStockInventory(User user){
    if (user.getStockInventory().empty() == 1){
        std::cout << redTextStart << "\nNo investments made\n" << coloredTextEnd;
    }
    for(std::pair<std::string, int> pair : user.getStockInventory()){
        std::cout << greenTextStart << "\nStock symbol: " << yellowTextStart << pair.first 
        << greenTextStart << "\nAmount of shares: " << yellowTextStart << pair.second << "\n";
    }
}

//CREATED BY CHATGPT:
int Menu::menuInputAndCheck(const int& min, const int& max) {
    std::string input;
    int choice;

    while (true) {
        std::getline(std::cin, input);
        try {
            choice = std::stoi(input);
            if (choice >= min && choice <= max){
                std::system("clear");
                return choice;
            }

            std::cout << "\nPlease enter a " << redTextStart << "number" << coloredTextEnd << " between " << min << " and " << max << ": ";
        } catch (const std::invalid_argument&) {
            std::cout << "\nThat is not a " << redTextStart << "number" << coloredTextEnd << ". Try again: ";
        } catch (const std::out_of_range&) {
            std::cout << "\nNumber out of " << redTextStart << "range" << coloredTextEnd << ". Try again: ";
        }
    }
}

void Menu::promptToBeginSetup(){
    std::cout << greenTextStart << "Welcome to StockSim!\n\n" << coloredTextEnd << "Here in the world of stock simulation, you" <<
        " are given the chance to learn about stocks and how they work in the real world \nWITHOUT losing" <<
        " your life-savings! Doesn't that sound great?\n\n";
}

std::string Menu::promptForUserName(){
        
    std::string input;
        
        std::cout << "Let's start by introducing yourself! What is your " << blueTextStart << 
            "name" << coloredTextEnd << "? ";
        
    std::getline(std::cin, input);
    std::system("clear");
    return input;
}

int Menu::promptForCashAmount(){

    printCashMenu();

    int choice = menuInputAndCheck(1,5);
    switch(choice){
        case 1:
            std::system("clear");
            return 100;
        case 2:
            std::system("clear");
            return 1000;
        case 3:
            std::system("clear");
            return 10000;   
        case 4:
            std::system("clear");
            return 100000;
        case 5:
            std::system("clear");
            return 1000000;
        default:
            return 0;
        }
}

std::string Menu::promptForSimulationMode(){

    printGameModeMenu();

    int choice = menuInputAndCheck(1, 3);
    switch(choice){
        case 1:
            return "Realistic";
        case 2:
            return "Arcade";
        case 3:
            return "Sandbox";
        default:
            return "";
    }
}

void Menu::promptToEndSetup(){

    std::string input;

    std::cout << yellowTextStart << "Okay your simulation is now set up. " << coloredTextEnd << "Although "
        << "this is meant to be a learning experience, " << yellowTextStart << "remember to have fun!\n" <<
        coloredTextEnd << "\nWhenever you feel ready to dive into the chaotic world of virtual stock " <<
        "trading type " << blueTextStart << "start" << coloredTextEnd << ": ";
    std::getline(std::cin, input);
    
    while (textTools::makeLowercase(input) != "start"){
        std::cout << "\nPlease enter " << redTextStart << "start" << coloredTextEnd << " to continue: ";
        std::getline(std::cin, input);
    }
    std::system("clear");
}

int Menu::promptToSearchStockBySymbol(const StockData& stocks){

    std::cout << "Please type in the stock's " << greenTextStart << "symbol" << coloredTextEnd << ":\n\n";
    std::string symbol;
    std::getline(std::cin, symbol);

    std::cout << "\nSearching for stock by " << greenTextStart << "symbol" << coloredTextEnd << "...\n\n";

    const Stock* stock = stocks.getStockBySymbol(symbol);

    if(stock != nullptr){
        std::cout << "Here is all available stock info:\n\n";
        stock->getInfo();
        return 0;
    }
    else{
        std::cout << redTextStart << "No stock found." << coloredTextEnd << "\n\nSelect an option:\n";
        return displaySearchStockErrorInterface();
    }
}

int Menu::promptToSearchStockByName(const StockData& stocks){
    std::cout << "Please type in the stock's " << greenTextStart << "name" << coloredTextEnd << ":\n\n";
    std::string name;
    std::getline(std::cin, name);
    std::cout << "\nSearching for stock by " << greenTextStart << "name" << coloredTextEnd << "...\n\n";

    const Stock* stock = stocks.getStockByName(name);

    if(stock != nullptr){
        std::cout << "Here is all available stock info:\n\n";
        stock->getInfo();
        return 0;
    }
    else{
        std::cout << redTextStart << "No stock found." << coloredTextEnd << "\n\nSelect an option:\n";
        return displaySearchStockErrorInterface();
    }
}

const Stock* Menu::promptToGetBoughtStockUsingSymbol(const StockData& stocks){

    while (true){
        std::cout << "Please type in the stock's " << greenTextStart << "symbol" << coloredTextEnd << ":\n\n";

        std::string symbol;
        std::getline(std::cin, symbol);

        const Stock* stock = stocks.getStockBySymbol(symbol);

        if(stock){
            std::system("clear");
            return stock;
        }
        
        std::cout << redTextStart << "\nNot a valid stock:\n\n" << coloredTextEnd;
        if(displaySearchStockErrorInterface() != 1){
            std::system("clear");
            return nullptr;
        }
    }
}

const Stock* Menu::promptToGetBoughtStockUsingName(const StockData& stocks){

    while (true){
        std::cout << "Please type in the stock's " << greenTextStart << "name" << coloredTextEnd << ":\n\n";

        std::string name;
        std::getline(std::cin, name);

        const Stock* stock = stocks.getStockByName(name);

        if(stock){
            std::system("clear");
            return stock;
        }
        
        std::cout << redTextStart << "\nNot a valid stock:\n\n" << coloredTextEnd;
        if(displaySearchStockErrorInterface() != 1){
            std::system("clear");
            return nullptr;
        }
    }
}

int Menu::promptToGetBoughtShares(int cash, const Stock* stock){
    std::cout << greenTextStart << "CURRENTLY BUYING: " << yellowTextStart << stock->getSymbol();

     std::cout << blueTextStart << "\n\nUser cash: " << yellowTextStart << "$" << cash << 
        blueTextStart << "\nShare price: " << yellowTextStart << "$" << stock->getPrice();
    int maxStocks = tradingTools::calculateStocksAbleToBuy(cash, stock->getPrice());
    
    std::cout << redTextStart << "\n\nYou can buy a total of: " << maxStocks << " shares\n\n"
        << coloredTextEnd << "How many shares would you like to buy? " <<
        redTextStart << "('0' to cancel)\n\n" << coloredTextEnd;
    
    return menuInputAndCheck(0, maxStocks);
}

int Menu::displayMainInterface(){

    printMainMenu();
    
    return menuInputAndCheck(1, 3);
}

int Menu::displayInvestInterface(){
    printInvestMenu();

    return menuInputAndCheck(1,4);
}

int Menu::displayPortfolioInterface(User user){
    printPortfolioMenu(user);

    return menuInputAndCheck(1,1);
}

int Menu::displaySearchStockInterface(){
    printSearchStockMenu();

    return menuInputAndCheck(1, 3);
}

int Menu::displaySearchStockErrorInterface(){
    printSearchStockErrorMenu();

    return menuInputAndCheck(1, 2);
}

int Menu::displayBuyStockInterface(){
    printBuyStockMenu();

    return menuInputAndCheck(1, 3);
}