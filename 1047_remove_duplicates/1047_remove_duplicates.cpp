#include <iostream>
#include<string>
#include"removeDuplicates.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    string s = "abbaca";

    string result = removeDuplicates(s);

    cout << result << endl;

    cin.get();
    return 0;
}

