#include <iostream>
#include"evalRPN.h"
#include<vector>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    vector<string> tokens = { "0","3","/" };
    int result = evalRPN(tokens);
    cout << "The result is " << result << endl;

    cin.get();
    return 0;
}
