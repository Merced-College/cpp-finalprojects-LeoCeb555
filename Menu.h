#define MENU_H
#ifdef MENU_H
#include <string>

namespace Menu{ //declared as namespace because Menu has no variables

    std::string makeLowercase(const std::string);
    std::string printFirstSequenceAndGetName();
    int promptForCashAmount();
    std::string promptForSimulationMode();
};

#endif