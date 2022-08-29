//  Libraries
//----------------
# include <string>

//  Namespaces
//----------------
using namespace std;

//  Structs, methods, functions
//--------------------------------

class Config
{
    string name;
    string value;

    public:
        Config()
        {}

        Config(string pName, string pValue = "")
        : name(pName), value(pValue)
        {}

        string& getName()
        {
            return name;
        }

        void setValue(string pValue)
        {
            value = pValue;
        }

        string toString()
        {
            return (name + ": " + value);
        }
};