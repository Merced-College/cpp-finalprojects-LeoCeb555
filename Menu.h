#define MENU_H
#ifdef MENU_H
#include <string>
#include <vector>
#include "StockData.h"
#include "User.h"

namespace Menu{

    class Menu{
        private:
            std::vector<std::string> positions;
            std::vector<std::string> actions;
        public:
            const std::string getAction(int i) const;
            const std::string getPosition(int i) const;
            void addButton(std::string position, std::string action);
            void printButton(int i);
            void printAllButtons();
        };

    void printCashMenu();
    void printGameModeMenu();
    void printMainMenu();
    void printInvestMenu();
    void printPortfolioMenu(User user);
    void printSearchStockMenu();
    void printSearchStockErrorMenu();
    void printBuyStockMenu();
    void printStockInventory(User user);
    
    int menuInputAndCheck(const int& min, const int& max);

    void promptToBeginSetup();
    std::string promptForUserName();
    int promptForCashAmount();
    std::string promptForSimulationMode();
    void promptToEndSetup();
    int promptToSearchStockBySymbol(const StockData& stocks);
    int promptToSearchStockByName(const StockData& stocks);
    const Stock* promptToGetBoughtStockUsingSymbol(const StockData& stocks);
    const Stock* promptToGetBoughtStockUsingName(const StockData& stocks);
    int promptToGetBoughtShares(int cash, const Stock* stock);
    int promptToBuyStockByName(int cash, const StockData& stocks);

    int displayMainInterface();
    int displayInvestInterface();
    int displayPortfolioInterface(User user);
    int displaySearchStockInterface();
    int displaySearchStockErrorInterface();
    int displayBuyStockInterface();

};

#endif