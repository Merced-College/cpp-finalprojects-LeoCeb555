#define SIMULATIONSTATE_H
#ifdef SIMULATIONSTATE_H
#include <string>
#include "User.h"
#include "Menu.h"
#include "StockData.h"

class SimulationState{
private:
    std::string simulationMode;
    User user;
    StockData stocks;
public:
    std::string getSimulationMode() const;
    void setSimulationMode(const std::string mode);
    void setupSimulation(User user);
    void runSimulation(User user);
};

#endif