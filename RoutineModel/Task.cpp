//----------------
// Libraries    ||
//----------------

# include <string>

// Validacion de reentrancia y redeclaraciones #ifdef #ifndef #endif

//----------------
// Constants    ||
//----------------

//----------------
// Namespaces   ||
//----------------

using namespace std;

//--------------------------------
// Structs, methods, functions  ||
//--------------------------------

enum TaskType
{
    SINGLE_DEVICE = 0,
    DEVICE_TYPE = 1
};

struct Task
{
    TaskType type;
    string action;
    //List<string> config
    
    virtual void runTask() =0;
};

struct SingleTask : public Task
{
    //Device ptrDevice

    SingleTask(string pAction): Task()
    {
        type = TaskType::SINGLE_DEVICE;
        action = pAction;
        //config = pConfig;
        //ptrDevice pDevice
    }

    void runTask()
    {
        // Device.execute(action) ? Running {action} : Unknown action!
        // Device.setConfig(config)
    }
};

struct DeviceTask : public Task
{
    //List<Device> ptrDevices

    DeviceTask(string pAction): Task()
    {
        type = TaskType::DEVICE_TYPE;
        action = pAction;
        //config = pConfig;
        //ptrDevices = pDevices;
    }

    void runTask()
    {
        // for (Device ptrDevice: ptrDevices)
        // {
        //      Device.execute(action) ? Running {action} : Unknown action!
        //      Device.setConfig(config)
        // }
    }
};

struct Routine
{
    string name;
    // List<Task> tasks;

    void runRoutine()
    {
        // for (Task ptrTask : tasks) {runTask()}
    }
};

//----------------
// Main program ||
//----------------