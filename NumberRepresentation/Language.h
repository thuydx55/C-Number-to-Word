#include <vector>
#include <string>

#ifndef LANGUAGE_H
#define LANGUAGE_H

enum LanguageType
{
    English,
    Vietnamese
};

class Language
{
public:

    virtual ~Language();

    static Language* getLanguage(LanguageType type);

    virtual const std::vector<std::string>& getOnes() = 0;
    virtual const std::vector<std::string>& getTeens() = 0;
    virtual const std::vector<std::string>& getTens() = 0;
    virtual const std::vector<std::string>& getPowers() = 0;
    virtual const std::string& getHundred() = 0;
    virtual const std::string& getConnectiveHundredsAndNext() = 0;
    virtual const std::string& getConnectiveTensAndOnes() = 0;
    virtual const std::string& getNegative() = 0;
};

#endif // LANGUAGE_H