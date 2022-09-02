//  Libraries
//----------------
# pragma once
# include <string>
# include "Array.hpp"
# include "Config.hpp"

//  Structs & Functions
//--------------------------
enum DeviceType
{
    LIGHTBULB = 0,
    DOOR_SENSOR = 1,
    SMOKE_DETECTOR = 2,
    CAMERA = 3
};

class Device
{
    DeviceType type;
    std::string name;
    std::string room;

    Array<std::string> actions;
    Array<Config> parameters;

    public:
        Device(){}
        Device(DeviceType pType, std::string pName, std::string pRoom);
        void print();
        void execute(const std::string& pAction);
        void setConfigs(Array<std::string>& pValues);

    private:
        void init();
        bool hasAction(const std::string& pAction);
        void printActions();
        void printParameters();
};