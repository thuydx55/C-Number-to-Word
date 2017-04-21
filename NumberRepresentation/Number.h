#include <string>
#include <stack>
#include <vector>

#include "Language.h"

#ifndef NUMBER_H
#define NUMBER_H

class Number
{
    std::string mNumStr;

    std::string getElement(const std::vector<std::string>& arr, const char& value);
    // Divide string into groups by length. First has 12 characters, each others have 9 characters
    std::stack<std::string> divideStringToBigGroup(const std::string &numStr);
    // Divide string into groups by length. Each has 3 characters
    std::stack<std::string> divideStringToSmallGroup(const std::string &numStr);
public:
    Number(std::string pNumStr);
    ~Number();
    
    bool isValid();
    std::string getTextRepresentation(LanguageType type = LanguageType::English);
};

#endif // NUMBER_H