#include "Language.h"

#include <vector>

#ifndef LANGUAGE_ENGLISH_H
#define LANGUAGE_ENGLISH_H

class LanguageEnglish : public Language
{
public:

    ~LanguageEnglish();

    const std::vector<std::string>& getOnes();
    const std::vector<std::string>& getTeens();
    const std::vector<std::string>& getTens();
    const std::vector<std::string>& getPowers();
    const std::string& getHundred();
    const std::string& getConnectiveHundredsAndNext();
    const std::string& getConnectiveTensAndOnes();
    const std::string& getNegative();
};

#endif // LANGUAGE_ENGLISH_H