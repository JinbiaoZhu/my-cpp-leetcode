#include "evalRPN.h"
#include<vector>
#include<string>
#include<stack>
#include<iostream>

using namespace std;

int evalRPN(vector<string>& tokens)
{

    stack<long long> stackChar;

    for (int i = 0; i < tokens.size(); i++) 
    {
        cout << "The char is " << tokens[i] << endl;
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") 
        {
            long long nums_1 = stackChar.top(); stackChar.pop();
            long long nums_2 = stackChar.top(); stackChar.pop();
            cout << "nums_1: " << nums_1 << " nums_2: " << nums_2 << endl;
            if (tokens[i] == "+") { stackChar.push(nums_2 + nums_1); }
            if (tokens[i] == "-") { stackChar.push(nums_2 - nums_1); }
            if (tokens[i] == "*") { stackChar.push(nums_2 * nums_1); }
            if (tokens[i] == "/") { stackChar.push(nums_2 / nums_1);  cout << "nums_2 / nums_1 is: " << nums_2 / nums_1 << endl; }
        }
        else
        {
            stackChar.push(stoll(tokens[i]));
        }
    }
    return stackChar.top();
}
