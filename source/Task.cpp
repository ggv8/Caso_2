//  Libraries
//----------------
# include "headers/Task.hpp"

//  Structs & Functions
//--------------------------
void Task::runTask()
{
    ptrDevice->execute(action);
    ptrDevice->setConfigs(config);
}