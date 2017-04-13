#include "LanguageVietnamese.h"

using namespace std;

const vector<string> ones = 
    {
        "không",    "một",      "hai",      "ba",       "bốn",
        "năm",      "sáu",      "bảy",      "tám",      "chín"
    };
const vector<string> teens = 
    {
        "mười",     "mười một", "mười hai", "mười ba",  "mười bốn",
        "mười năm", "mười sáu", "mười bảy", "mười tám", "mười chín"
    };
const vector<string> tens = 
    {
        "",         "",         "hai mươi", "ba mươi",  "bốn mươi",
        "năm mươi", "sáu mươi", "bảy mươi", "tám mươi", "chín mươi"
    };
const vector<string> powers = 
    {
        "",         "nghìn",     "triệu",    "tỉ"
    };

const string hundred = "trăm";
const string connectiveHundredsAndNext = "";
const string connectiveTensAndOnes = "linh";
const string negative = "âm";

LanguageVietnamese::~LanguageVietnamese() {}

const std::vector<std::string>& LanguageVietnamese::getOnes() {
    return ones;
}

const std::vector<std::string>& LanguageVietnamese::getTeens() {
    return teens;
}

const std::vector<std::string>& LanguageVietnamese::getTens() {
    return tens;
}

const std::vector<std::string>& LanguageVietnamese::getPowers() {
    return powers;
}

const std::string& LanguageVietnamese::getHundred() {
    return hundred;
}

const std::string& LanguageVietnamese::getConnectiveHundredsAndNext() {
    return connectiveHundredsAndNext;
}

const std::string& LanguageVietnamese::getConnectiveTensAndOnes() {
    return connectiveTensAndOnes;
}

const std::string& LanguageVietnamese::getNegative() {
    return negative;
}
