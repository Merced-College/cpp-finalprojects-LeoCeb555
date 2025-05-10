#define MENU_H
#ifdef MENU_H
#include <string>
#include <vector>

namespace Menu{
    // Constants for color formatting
    const std::string blueTextStart = "\033[1;34m";
    const std::string blueTextEnd = "\033[0m";
    const std::string greenTextStart = "\033[1;32m";
    const std::string greenTextEnd = "\033[0m";
    const std::string redTextStart = "\033[1;31m";
    const std::string redTextEnd = "\033[0m";
    const std::string yellowTextStart = "\033[1;33m";
    const std::string yellowTextEnd = "\033[0m";

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

    std::string makeLowercase(const std::string);
    void printCashMenu();
    void printGameModeMenu();
    void printMainMenu();
    void printInvestMenu();
    int menuInputAndCheck(int min, int max);
    void beginSetupPrompt();
    std::string promptForUserName();
    int promptForCashAmount();
    std::string promptForSimulationMode();
    void endSetupPrompt();
    int displayMainInterface();
    int displayInvestInterface();

};

#endif