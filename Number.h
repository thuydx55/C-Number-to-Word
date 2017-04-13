#include <string>
#include <stack>
#include <vector>

class Number
{
    std::string mNumStr;

    std::string getElement(const std::string arr[], const char& value);
    std::stack<std::string> divideStringToGroupOfTwelve(const std::string &numStr);
    std::stack<std::string> divideStringToGroupOfThree(const std::string &numStr);
public:
    Number(std::string pNumStr);
    ~Number();
    
    bool isValid();
    std::string getTextRepresentation();
};