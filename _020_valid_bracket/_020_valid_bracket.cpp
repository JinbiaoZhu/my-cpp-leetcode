#include <iostream>
#include<string>
#include"validBracket.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    string s = "(}";
    bool result = isValid(s);

    if (result) { cout << "Valid" << endl; }
    else { cout << "Invalid" << endl; }

    cin.get();
    return 0;
}
