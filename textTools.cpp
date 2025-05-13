#include "textTools.h"

std::string textTools::makeLowercase(const std::string word){
    std::string temp;
    for (char a : word){
        temp += (tolower(a));
    }
    return temp;
}