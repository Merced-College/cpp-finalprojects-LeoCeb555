#ifndef TEXT_TOOLS
#define TEXT_TOOLS
#include <string>

//textTools is only used for text formatting and string manipulation
namespace textTools{
    // Constants for color formatting
    const std::string blueTextStart = "\033[1;34m";
    const std::string greenTextStart = "\033[1;32m";
    const std::string redTextStart = "\033[1;31m";
    const std::string yellowTextStart = "\033[1;33m";
    const std::string coloredTextEnd = "\033[0m";

    std::string makeLowercase(const std::string);
};

#endif