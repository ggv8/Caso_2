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

class Config
{
    string name;
    string value;

    public:
        Config()
        {}

        Config(string pName, string pValue = "")
        {
            name = pName;
            value = pValue;
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

//----------------
// Main program ||
//----------------
