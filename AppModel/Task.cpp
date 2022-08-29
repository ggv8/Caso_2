//  Libraries
//----------------

# include <string>
# include "Device.cpp"
# include "LinearADT/Array.cpp"

using namespace std;

//  Structs, methods, functions
//--------------------------------

struct Task
{
    Device* ptrDevice;
    string action;
    Array<string> config;
    
    void runTask()
    {
        ptrDevice->execute(action);
        ptrDevice->setConfigs(config);
    }
};