#define MENU_H
#ifdef MENU_H
#include <string>
#include <vector>
#include "StockData.h"
#include "User.h"
#include "StockLogic.h"

//Menu handles user input, input logic, and simulator output
namespace Menu{

    class Menu{
        private:
            std::vector<std::string> positions; //vector to track button positions
            std::vector<std::string> actions; //vector to track button actions
        public:
            const std::string& getAction(int i) const; //accessor for button action at i index
            const std::string& getPosition(int i) const; //accessor for button position at i index
            void addButton(const std::string& position, const std::string& action);
            void printButton(int i) const;
            void printAllButtons() const;
        };

    void printCashMenu();
    void printGameModeMenu();
    void printMainMenu();
    void printInvestMenu();
    void printPortfolioMenu(const User& user);
    void printSearchStockMenu();
    void printSearchStockErrorMenu();
    void printBuyStockMenu();
    void printSellStockMenu();
    void printStockInventory(const User& user);
    void printViewRankingsMenu();
    void printTopMoversMenu(const StockData& data);
    void printMostPopularMenu(const StockData& data);
    void printStocksToWatchMenu(const StockData& data);
    
    int menuInputAndCheck(const int min, const int max);

    void promptToBeginSetup();
    std::string promptForUserName();
    int promptForCashAmount();
    std::string promptForSimulationMode();
    void promptToEndSetup();
    int promptToSearchStockBySymbol(const StockData& stocks);
    int promptToSearchStockByName(const StockData& stocks);
    const Stock* promptToGetStockUsingSymbol(const StockData& stocks);
    const Stock* promptToGetStockUsingName(const StockData& stocks);
    int promptToGetBoughtShares(int cash, const Stock*& stock);
    int promptToGetSoldShares(int cash, int stockAmount, const Stock*& stock);
    int promptToSellShares(int cash, int maxStocks, const Stock*& stock);
    int promptToBuyStockByName(int cash, const StockData& stocks);

    int displayMainInterface();
    int displayInvestInterface();
    int displayPortfolioInterface(const User& user);
    int displaySearchStockInterface();
    int displaySearchStockErrorInterface();
    int displayBuyStockInterface();
    int displaySellStockInterface();
    int displayViewRankingsInterface();

};

#endif