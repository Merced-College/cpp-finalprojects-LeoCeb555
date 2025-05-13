#define SIMULATIONSTATE_H
#ifdef SIMULATIONSTATE_H
#include <string>
#include "User.h"
#include "Menu.h"
#include "StockData.h"

//SimulationState is a state machine that runs the main simulation loop and controls Menu transition logic; ties other classes together
class SimulationState{
private:
    std::string simulationMode;
    User user;
    StockData stocks;
public:
    std::string getSimulationMode() const;
    void setSimulationMode(const std::string mode);
    void setupSimulation();
    void runSimulation();
};

#endif