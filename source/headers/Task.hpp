//  Libraries
//----------------
# pragma once
# include "Device.hpp"

//  Structs & Functions
//--------------------------
struct Task
{
    Device* ptrDevice;
    std::string action;
    Array<std::string> config;
    
    void runTask();
};