#define SIMULATIONSTATE_H
#ifdef SIMULATIONSTATE_H
#include <string>

class simulationState{
private:
    std::string userName;
    int cashAmount;
    const std::string gameMode;
public:
    std::string getUserName() const;
    void setUserName(const std::string name);
    int getCashAmount() const;
    void setCashAmount(const int cash);
};

#endif