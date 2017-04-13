#include "Number.h"
#include <iostream>

using namespace std;

Number::Number(string pNumStr) {
    mNumStr = pNumStr;
}

Number::~Number() {

}

bool Number::isValid() {
    short startIdx = 0;
    if (mNumStr[0] == '-')
        startIdx++;

    for(short i = startIdx; i < mNumStr.size(); i++ ) {
        if(mNumStr[i] < '0' || mNumStr[i] > '9')
            return false;
    }

    return true;
}

string Number::getTextRepresentation(LanguageType type) {
    vector<string> words;
    Language* lang = Language::getLanguage(type);

    string tempNumStr = string(mNumStr);

    if (tempNumStr[0] == '-') {
        words.push_back(lang->getNegative());
        tempNumStr.erase(0,1);
    }

    while(tempNumStr.size() % 3)
        tempNumStr = '0' + tempNumStr;

    stack<string> bigGroups = divideStringToBigGroup(tempNumStr);
    while(!bigGroups.empty()) {
        string bigGroup = bigGroups.top();
        bigGroups.pop();

        // cout << bigGroup << endl;

        stack<string> groups = divideStringToSmallGroup(bigGroup);

        while(!groups.empty()) {
            string subNumber = groups.top();
            groups.pop();

            // cout << subNumber << endl;

            if (subNumber[0] == '0' && subNumber[1] == '0' && subNumber[2] == '0')
                continue;

            if (subNumber[0] > '0') {
                words.push_back(getElement(lang->getOnes(), subNumber[0]));
                words.push_back(lang->getHundred());
            }

            if (subNumber[1] == '0' || subNumber[1] > '1') {
                if (subNumber[1] > '1')
                    words.push_back(getElement(lang->getTens(), subNumber[1]));
                if (subNumber[2] > '0') {
                    if (words.size())
                        words.push_back(lang->getConnectiveHundredsAndNext());
                    if (subNumber[1] == '0' && words.size() > 0)
                        words.push_back(lang->getConnectiveTensAndOnes());
                    words.push_back(getElement(lang->getOnes(), subNumber[2]));
                }
            }
            else {
                words.push_back(lang->getConnectiveHundredsAndNext());
                words.push_back(getElement(lang->getTeens(), subNumber[2]));
            }
            const vector<string> powers = lang->getPowers();
            words.push_back(powers[groups.size()]);
            for (short i = 0; i < bigGroups.size(); i++) {
                words.push_back(powers[powers.size()-1]);
            }
        }
    }

    string result = "";
    for (short i = 0; i < words.size(); ++i)
    {
        if (words[i].length())
            result += words[i] + " ";
    }

    result = result.length() ? result : lang->getOnes()[0];

    delete lang;

    return result;
}

string Number::getElement(const vector<string>& arr, const char& value) {
    return arr[value - '0'];
}

// Divide string into groups by length. 
// First has 12 characters, each others have 9 characters but auto add '000' at the end
// E.g: 100001100001100001100001 ~ 100 001100001 100001100001
stack<string> Number::divideStringToBigGroup(const string &numStr) {
    stack<string> groups;

    short length = 12;
    for (short i = numStr.length()-1; i >= 0;) {
        string str = "";
        if (i >= length-1) {
            str = numStr.substr(i-(length-1), length);
            i -= length;
            length = 9;
        }
        else {
            str = numStr.substr(0, i+1);
            i -= length;
        }

        if (str.length() < 12)
            str = str + "000";
        groups.push(str);
    }

    return groups;
}

// Divide string into groups by length. Each has 3 characters
stack<string> Number::divideStringToSmallGroup(const string &numStr) {
    stack<string> groups;

    for (short i = numStr.length()-1; i >= 0; i -= 3) {
        if (i >= 2)
            groups.push(numStr.substr(i-2, 3));
        else
            groups.push(numStr.substr(0, i+1));
    }

    return groups;
}