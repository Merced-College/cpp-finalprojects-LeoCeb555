#include "Menu.h"
#include <iostream>
#include <string>
#include <cctype>

namespace Menu{
    // Constants for color formatting
    static const std::string blueTextStart = "\033[1;34m";
    static const std::string blueTextEnd = "\033[0m";
    static const std::string greenTextStart = "\033[1;32m";
    static const std::string greenTextEnd = "\033[0m";
    static const std::string redTextStart = "\033[1;31m";
    static const std::string redTextEnd = "\033[0m";
    static const std::string yellowTextStart = "\033[1;33m";
    static const std::string yellowTextEnd = "\033[0m";   

    std::string makeLowercase(const std::string word){
        std::string temp;
        for (char a : word){
            temp += (tolower(a));
        }
        return temp;
    }
    
    std::string printFirstSequenceAndGetName(){
        
        std::string input;
    
        std::cout << blueTextStart << "Welcome to StockSim!\n\n" << blueTextEnd << "Here in the world of stock simulation, you" <<
            " are given the chance to learn about stocks and how they work in the real world \nWITHOUT losing" <<
            " your life-savings! Doesn't that sound great?\n\nWhenever you feel are ready to " <<
            "dive into the chaotic world of virtual stock trading enter " << greenTextStart << "start " << 
            greenTextEnd << "into the prompt: ";
        std::cin >> input;
    
        while (makeLowercase(input) != "start"){
            std::cout << "Please enter start to continue: " << std::endl;
            std::cin >> input;
        }
    
        std::cout << "You're one step closer to trading some stocks! What is your name? ";
        std::cin >> input;
        return input;
    };
    
    void evaluateUserInput(const std::string input){
        if (input == ""){
    
        }
    };
}