#define SIMULATIONSTATE_H
#ifdef SIMULATIONSTATE_H
#include <string>

class simulationState{
private:
    std::string userName;
    int cashAmount;
    std::string simulationMode;
public:
    std::string getUserName() const;
    void setUserName(const std::string name);
    int getCashAmount() const;
    void setCashAmount(const int cash);
    std::string getSimulationMode() const;
    void setSimulationMode(const std::string mode);
    void setupSimulation();
};

#endif