#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string ones[] = 
    {
        "zero",     "one",      "two",          "three",        "four",
        "five",     "six",      "seven",        "eight",        "nine"
    };
string teens[] = 
    {
        "ten",      "eleven",   "twelve",       "thirteen",     "fourteen",
        "fifteen",  "sixteen",  "seventeen",    "eighteen",     "nineteen"
    };
string tens[] = 
    {
        "",        "",          "twenty",       "thirty",       "fourty",
        "fifty",   "sixty",     "seventy",      "eighty",       "ninety"
    };
string powers[] = 
    {
        "",        "thousand",  "million",      "billion"
    };

string hundred = "hundred";
string connectiveHundredsAndNext = "and";
string connectiveTensAndOnes = "";
string negative = "negative";

// string ones[] = 
//     {
//         "không",    "một",      "hai",      "ba",       "bốn",
//         "năm",      "sáu",      "bảy",      "tám",      "chín"
//     };
// string teens[] = 
//     {
//         "mười",     "mười một", "mười hai", "mười ba",  "mười bốn",
//         "mười năm", "mười sáu", "mười bảy", "mười tám", "mười chín"
//     };
// string tens[] = 
//     {
//         "",         "",         "hai mươi", "ba mươi",  "bốn mươi",
//         "năm mươi", "sáu mươi", "bảy mươi", "tám mươi", "chín mươi"
//     };
// string powers[] = 
//     {
//         "",         "ngàn",     "triệu",    "tỉ"
//     };

// string hundred = "trăm";
// string connectiveHundredsAndNext = "";
// string connectiveTensAndOnes = "linh";
// string negative = "âm";

string getElement(const string arr[], const char& value) {
    return arr[value - '0'];
}

stack<string> divideStringToGroupOfTwelve(const string &numStr) {
    stack<string> groups;

    for (short i = numStr.length()-1; i >= 0; i -= 12) {
        if (i >= 11)
            groups.push(numStr.substr(i-11, 12));
        else
            groups.push(numStr.substr(0, i+1));
    }

    return groups;
}

stack<string> divideStringToGroupOfThree(const string &numStr) {
    stack<string> groups;

    for (short i = numStr.length()-1; i >= 0; i -= 3) {
        if (i >= 2)
            groups.push(numStr.substr(i-2, 3));
        else
            groups.push(numStr.substr(0, i+1));
    }

    return groups;
}

string process(string &numStr) {
    vector<string> words;

    if (numStr[0] == '-') {
        words.push_back(negative);
        numStr.erase(0,1);
    }

    while(numStr.size() % 3)
        numStr = '0' + numStr;

    stack<string> twelveGroups = divideStringToGroupOfTwelve(numStr);
    while(!twelveGroups.empty()) {
        string group12Str = twelveGroups.top();
        twelveGroups.pop();

        // cout << group12Str << endl;

        stack<string> groups = divideStringToGroupOfThree(group12Str);

        while(!groups.empty()) {
            string subNumber = groups.top();
            groups.pop();

            // cout << subNumber << endl;

            if (subNumber[0] == '0' && subNumber[1] == '0' && subNumber[2] == '0')
                continue;

            if (subNumber[0] > '0') {
                words.push_back(getElement(ones, subNumber[0]));
                words.push_back(hundred);
            }

            if (subNumber[1] == '0' || subNumber[1] > '1') {
                if (subNumber[1] > '1')
                    words.push_back(getElement(tens, subNumber[1]));
                if (subNumber[2] > '0') {
                    if (words.size())
                        words.push_back(connectiveHundredsAndNext);
                    if (subNumber[1] == '0' && words.size() > 0)
                        words.push_back(connectiveTensAndOnes);
                    words.push_back(getElement(ones, subNumber[2]));
                }
            }
            else {
                words.push_back(connectiveHundredsAndNext);
                words.push_back(getElement(teens, subNumber[2]));
            }

            words.push_back(powers[twelveGroups.size()]);
            words.push_back(powers[groups.size()]);
        }
    }

    string result = "";
    for (short i = 0; i < words.size(); ++i)
    {
        if (words[i].length())
            result += words[i] + " ";
    }

    result = result.length() ? result : ones[0];

    return result;
}

bool validate(const string &numStr) {
    short startIdx = 0;
    if (numStr[0] == '-')
        startIdx++;

    for(short i = startIdx; i < numStr.size(); i++ ) {
        if(numStr[i] < '0' || numStr[i] > '9')
            return false;
    }

    return true;
}

int main(int argc, char const *argv[])
{

    if ( argc != 2 ) // argc should be 2 for correct execution
        // We print argv[0] assuming it is the program name
        cout<<"usage: "<< argv[0] <<" <number string>\n";
    else {
        string numStr = argv[1];

        if (!validate(numStr)) {
            cout << "'" << numStr << "' is not a number!" << endl;
            return 1;
        }

        cout << process(numStr) << endl;
    }
    // string numStr = "-100001100001100001100001";

    // if (!validate(numStr)) {
    //     cout << "'" << numStr << "' is not a number!" << endl;
    //     return 1;
    // }

    // cout << process(numStr) << endl;

    return 0;
}