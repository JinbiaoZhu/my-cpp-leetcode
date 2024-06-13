#include <iostream>
#include"BasicMethod.h"

int main()
{
    std::cout << "Hello World!\n";

    bool result;

    string s1 = "aaeed";
    string s2 = "aaeec";
    string t = "eaead";

    BasicMethod basic_method;
    result = basic_method.isValidAnagram(s1, t);
    if (result) { cout << "Valid" << endl; }
    else { cout << "Invalid" << endl; }

    result = basic_method.isValidAnagram(s2, t);
    if (result) { cout << "Valid" << endl; }
    else { cout << "Invalid" << endl; }

    cin.get();
    return 0;
}
