//  Libraries
//----------------
# include "source/headers/Task.hpp"
# include "source/headers/Routine.hpp"
# include "source/headers/Device.hpp"
# include "source/headers/List.hpp"

//  Directives
//----------------

//  Constants
//----------------

//  Namespaces
//----------------
using namespace std;

//  Structs & Functions
//--------------------------

//  Main program
//----------------

int main()
{
    Device test (DeviceType::LIGHTBULB, "Bombillo_1", "Test");
    test.print();
    test.execute("ON");
    test.execute("JUMP");

    Array<string> goodConfig = {2, new string[2] {"#888888", "low"}};
    Array<string> badConfig = {5, {}};
    Array<string> anotherBadConfig = {1, new string[1] {"test"}};

    test.setConfigs(anotherBadConfig);
    test.setConfigs(badConfig);
    test.setConfigs(goodConfig);
    test.print();
    return 0;
}