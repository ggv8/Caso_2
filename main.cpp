//  Libraries
//----------------
# include "AppModel/Routine.cpp"
# include "AppModel/Task.cpp"
# include "AppModel/Device.cpp"
# include "AppModel/Config.cpp"
# include "AppModel/LinearADT/Array.cpp"
# include "AppModel/LinearADT/List.cpp"

//  Directives
//----------------

//  Constants
//----------------

//  Namespaces
//----------------

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