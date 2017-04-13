#include "LanguageEnglish.h"

using namespace std;

const vector<string> ones = 
    {
        "zero",     "one",      "two",          "three",        "four",
        "five",     "six",      "seven",        "eight",        "nine"
    };
const vector<string> teens = 
    {
        "ten",      "eleven",   "twelve",       "thirteen",     "fourteen",
        "fifteen",  "sixteen",  "seventeen",    "eighteen",     "nineteen"
    };
const vector<string> tens = 
    {
        "",        "",          "twenty",       "thirty",       "fourty",
        "fifty",   "sixty",     "seventy",      "eighty",       "ninety"
    };
const vector<string> powers = 
    {
        "",        "thousand",  "million",      "billion"
    };

const string hundred = "hundred";
const string connectiveHundredsAndNext = "and";
const string connectiveTensAndOnes = "";
const string negative = "negative";

LanguageEnglish::~LanguageEnglish() {}

const std::vector<std::string>& LanguageEnglish::getOnes() {
    return ones;
}

const std::vector<std::string>& LanguageEnglish::getTeens() {
    return teens;
}

const std::vector<std::string>& LanguageEnglish::getTens() {
    return tens;
}

const std::vector<std::string>& LanguageEnglish::getPowers() {
    return powers;
}

const std::string& LanguageEnglish::getHundred() {
    return hundred;
}

const std::string& LanguageEnglish::getConnectiveHundredsAndNext() {
    return connectiveHundredsAndNext;
}

const std::string& LanguageEnglish::getConnectiveTensAndOnes() {
    return connectiveTensAndOnes;
}

const std::string& LanguageEnglish::getNegative() {
    return negative;
}
