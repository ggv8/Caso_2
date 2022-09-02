//  Libraries
//----------------
# include <iostream>
# include "headers/Device.hpp"

//  Constants
//----------------
const char* type_names[4] = {"Lightbulb", "Door sensor", "Smoke detector", "Camera"};

//  Namespaces
//----------------
using namespace std;

//  Structs & Functions
//--------------------------

    //  Public methods
    //---------------------
    Device::Device(DeviceType pType, string pName, string pRoom)
    : type(pType), name(pName), room(pRoom)
    {
        init();
    }

    void Device::print()
    {
        cout << type_names[type] << " " + name + " at room " + room + "\n";
        printActions();
        printParameters();
    }

    void Device::execute(const string& pAction)
    {
        if (hasAction(pAction))
        {
            cout << "Running action: " + pAction + "\n";
        } else {
            cout << "Error: Unknow action for " << type_names[type] << "\n";
        }
    }

    void Device::setConfigs(Array<string>& pValues)
    {
        if (parameters.size != pValues.size)
        {
            cout << "Error: Unexpected parameters for " << type_names[type] << "\n";
            return;
        }
        for (int index = 0; index < pValues.size; index++)
        {
            parameters.get(index).setValue(pValues.get(index));
        }
        cout << "Configuration set for " << name << "\n";
    }

    //  Private methods
    //----------------------
    void Device::init()
    {
        switch (type)
        {
            case LIGHTBULB:
                actions = {2, new string[2] {"ON", "OFF"}};
                parameters = {2, new Config[2] { {"Color", "#ffffff"}, {"Brightness", "high"} }};
                break;

            case DOOR_SENSOR:
                actions = {6, new string[6] {"ON", "OFF", "OPEN", "CLOSE", "ALARM", "NOTIFY"}};
                parameters = {0, {}};
                break;
            
            case SMOKE_DETECTOR:
                actions = {3, new string[3] {"ON", "OFF", "ALARM"}};
                parameters = {1, new Config[1] { {"Sensibility", "normal"} }};
                break;
            
            case CAMERA:
                actions = {2, new string[2] {"ON", "OFF"}};
                parameters = {0, {}};
                break;
            
            default:
                actions = {0, {}};
                parameters = {0, {}};
        }
    }

    bool Device::hasAction(const string& pAction)
    {
        for (int index = 0; index < actions.size; index++)
        {
            if (actions.get(index) == pAction)
            {
                return true;
            }
        }
        return false;
    }

    void Device::printActions()
    {
        int index = 0;
        int end = actions.size - 1;
        cout << "Actions: ";
        for (; index < end; index++)
        {
            cout << actions.get(index) + ", ";
        }
        cout << actions.get(end) << "\n";
    }

    void Device::printParameters()
    {
        int index = 0;
        int end = actions.size - 1;
        cout << "Parameters: ";
        for (; index < end; index++)
        {
            cout << "{" + parameters.get(index).toString() + "}, ";
        }
        cout << "{" + parameters.get(end).toString() + "}\n";
    }