#include <iostream>
#include <string>
#include <map>
#include <sstream>

#include "NumberRepresentation/Number.h"
#include "NumberRepresentation/Language.h"

using namespace std;

const map<string, string> data = {
    {"0", "zero"},
    {"1", "one"},
    {"10", "ten"},
    {"15", "fifteen"},
    {"20", "twenty"},
    {"21", "twenty one"},
    {"100", "one hundred"},
    {"101", "one hundred and one"},
    {"110", "one hundred and ten"},
    {"120", "one hundred and twenty"},
    {"121", "one hundred and twenty one"},
    {"999", "nine hundred and ninety nine"},

    {"1000", "one thousand"},
    {"1001", "one thousand and one"},
    {"1010", "one thousand and ten"},
    {"1020", "one thousand and twenty"},
    {"1021", "one thousand and twenty one"},
    {"1100", "one thousand one hundred"},
    {"1101", "one thousand one hundred and one"},
    {"1110", "one thousand one hundred and ten"},
    {"1120", "one thousand one hundred and twenty"},
    {"1121", "one thousand one hundred and twenty one"},
    {"9999", "nine thousand nine hundred and ninety nine"},

    {"10000", "ten thousand"},
    {"10001", "ten thousand and one"},
    {"10010", "ten thousand and ten"},
    {"10020", "ten thousand and twenty"},
    {"10021", "ten thousand and twenty one"},
    {"10100", "ten thousand one hundred"},
    {"10101", "ten thousand one hundred and one"},
    {"10110", "ten thousand one hundred and ten"},
    {"10120", "ten thousand one hundred and twenty"},
    {"10121", "ten thousand one hundred and twenty one"},
    {"21000", "twenty one thousand"},
    {"21001", "twenty one thousand and one"},
    {"21010", "twenty one thousand and ten"},
    {"21020", "twenty one thousand and twenty"},
    {"21021", "twenty one thousand and twenty one"},
    {"21100", "twenty one thousand one hundred"},
    {"21101", "twenty one thousand one hundred and one"},
    {"21110", "twenty one thousand one hundred and ten"},
    {"21120", "twenty one thousand one hundred and twenty"},
    {"21121", "twenty one thousand one hundred and twenty one"},
    {"99999", "ninety nine thousand nine hundred and ninety nine"},

    {"100000", "one hundred thousand"},
    {"100001", "one hundred thousand and one"},
    {"100010", "one hundred thousand and ten"},
    {"100020", "one hundred thousand and twenty"},
    {"100021", "one hundred thousand and twenty one"},
    {"100100", "one hundred thousand one hundred"},
    {"100101", "one hundred thousand one hundred and one"},
    {"100110", "one hundred thousand one hundred and ten"},
    {"100120", "one hundred thousand one hundred and twenty"},
    {"100121", "one hundred thousand one hundred and twenty one"},
    {"101000", "one hundred and one thousand"},
    {"101001", "one hundred and one thousand and one"},
    {"101010", "one hundred and one thousand and ten"},
    {"101020", "one hundred and one thousand and twenty"},
    {"101021", "one hundred and one thousand and twenty one"},
    {"101100", "one hundred and one thousand one hundred"},
    {"101101", "one hundred and one thousand one hundred and one"},
    {"101110", "one hundred and one thousand one hundred and ten"},
    {"101120", "one hundred and one thousand one hundred and twenty"},
    {"101121", "one hundred and one thousand one hundred and twenty one"},
    {"999999", "nine hundred and ninety nine thousand nine hundred and ninety nine"},

    {"999999999999", "nine hundred and ninety nine billion nine hundred and ninety nine million nine hundred and ninety nine thousand nine hundred and ninety nine"},
    {"999999999999999", "nine hundred and ninety nine thousand billion nine hundred and ninety nine billion nine hundred and ninety nine million nine hundred and ninety nine thousand nine hundred and ninety nine"},
    {"999999999999999999999999", "nine hundred and ninety nine thousand billion billion nine hundred and ninety nine billion billion nine hundred and ninety nine million billion nine hundred and ninety nine thousand billion nine hundred and ninety nine billion nine hundred and ninety nine million nine hundred and ninety nine thousand nine hundred and ninety nine"},

    {"-0", "zero"},
    {"-1", "negative one"},
    {"-999", "negative nine hundred and ninety nine"},
};

int main(int argc, char const *argv[])
{
    int count = 0;
    int length = data.size();

    for (const auto &kv : data ) {
        count++;
        stringstream s;

        s << "[" << count << "/" << length << "]: ";

        Number num = Number(kv.first);
        if (!num.isValid()) {
            cout << s.str() << "FAILED - " << "'" << kv.first << "' is not a number!" << endl;
            continue;
        }

        string text = num.getTextRepresentation();
        if (text.compare(kv.second) != 0)
            cout << s.str() << "FAILED - " << kv.first << ": '" << text << "' is not equal to '" << kv.second << "'" << endl;
        else
            cout << s.str() << "SUCCEED - " << kv.first << endl;
    }

    return 0;
}