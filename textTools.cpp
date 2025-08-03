#include "textTools.h"

std::string textTools::makeLowercase(const std::string& word){
    std::string temp = word;
    for (char& a : temp){
        a = (tolower(a));
    }
    return temp;
}