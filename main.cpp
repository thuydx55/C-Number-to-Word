#include <iostream>

#include "NumberRepresentation/Number.h"
#include "NumberRepresentation/Language.h"

using namespace std;

int main(int argc, char const *argv[])
{
    if ( argc != 2 ) // argc should be 2 for correct execution
        // We print argv[0] assuming it is the program name
        cout << "usage: "<< argv[0] <<" <number string>\n";
    else {
        string numStr = argv[1];

        Number num(numStr);
        if (!num.isValid()) {
            cout << "'" << numStr << "' is not a number!" << endl;
            return 1;
        }

        cout << num.getTextRepresentation() << endl;
    }

    return 0;
}