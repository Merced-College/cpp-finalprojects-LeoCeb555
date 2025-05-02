#include "Menu.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

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
    
        std::cout << greenTextStart << "Welcome to StockSim!\n\n" << greenTextEnd << "Here in the world of stock simulation, you" <<
            " are given the chance to learn about stocks and how they work in the real world \nWITHOUT losing" <<
            " your life-savings! Doesn't that sound great?\n\nWhenever you feel are ready to " <<
            "dive into the chaotic world of virtual stock trading enter " << blueTextStart << "start " << 
            blueTextEnd << "into the prompt: ";
        std::cin >> input;
    
        while (makeLowercase(input) != "start"){
            std::cout << std::endl;
            std::cout << "Please enter " << redTextStart << "start" << redTextEnd << " to continue: ";
            std::cin >> input;
        }
        
        std::cout << "\nYou're one step closer to trading some stocks! What is your " << blueTextStart << "name" <<
            blueTextEnd << "? ";
        std::cin >> input;
        std::system("clear");
        return input;
    };

    int promptForCashAmount(){
        int input;

        std::cout << "What an absolutely magnificent name that is. Now, let's get into your finances." <<
            " How much " << blueTextStart << "cash" << blueTextEnd << " are you starting with?\n\n" <<
            greenTextStart <<"1. $100\n\n2. $1000 \n\n3. $10000\n\n4. $100000\n\n5. $1000000\n\n"
            << greenTextEnd;

        std::cin >> input;

        while(input != 100 && input != 1000 && input != 10000 && input != 100000 && input != 1000000){
            std::cout << std::endl;
            std::cout << "Please enter a valid amount of " << redTextStart << "cash" << redTextEnd <<
                " to continue (enter cash amount): ";
            std::cin >> input;
        }
        std::system("clear");
        return input;
    };

    std::string promptForSimulationMode(){
        std::string input;

        std::cout << "Great, now here comes to fun part! What " << blueTextStart 
            << "mode" << blueTextEnd << " do you want to use?\n\n" << greenTextStart <<
            "1. Realistic\n\n2. Arcade " << redTextStart << "(UNDER CONSTRUCTION)\n\n"
            << greenTextStart << "3. Sandbox " << redTextStart << "(UNDER CONSTRUCTION)\n\n" << redTextEnd;

        std::cin >> input;
        
        while(makeLowercase(input) != "realistic"){
            std::cout << std::endl;
            std::cout << "Please enter a valid " << redTextStart << "mode" << redTextEnd 
            << " to continue (enter name of mode): ";
            std::cin >> input;
        }
        std::system("clear");
        return input;
    };
    
}