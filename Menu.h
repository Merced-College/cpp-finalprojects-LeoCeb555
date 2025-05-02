#define MENU_H
#ifdef MENU_H
#include <string>

namespace Menu{ //declared as namespace because Menu has no variables

    std::string makeLowercase(const std::string);
    std::string printFirstSequenceAndGetName();
    void evaluateUserInput(const std::string input);
};

#endif