//  Libraries
//----------------
# include <string>

//  Structs, methods, functions
//--------------------------------
class Config
{
    std::string name;
    std::string value;

    public:
        Config()
        {}

        Config(std::string pName, std::string pValue = "")
        : name(pName), value(pValue)
        {}

        std::string& getName()
        {
            return name;
        }

        void setValue(std::string pValue)
        {
            value = pValue;
        }

        std::string toString()
        {
            return (name + ": " + value);
        }
};