//----------------
// Libraries    ||
//----------------
# include <string>
# include "DeviceType.cpp"
# include "Config.cpp"
# include "Room.cpp"
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

class Device
{
    DeviceType type;
    string name;
    Room room;
    //List<string> actions;
    Config parameters[];

};

//----------------
// Main program ||
//----------------