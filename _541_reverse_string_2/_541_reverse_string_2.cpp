#include <iostream>
#include<string>
#include"reverse_string.h"


int main()
{
    std::cout << "Hello World!\n";

    string s = "abcdefg";
    int k = 2;

    string result = reverseStr(s,k);

    cout << s << endl;
    cout << result << endl;

    cin.get();
    return 0;

}
