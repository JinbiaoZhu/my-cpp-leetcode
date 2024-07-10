#include "removeDuplicates.h"
#include<string>
#include<stack>

using namespace std;

string removeDuplicates(string s)
{
    stack<char> stackChar;
    string result = "";

    for (int index = 0; index < s.size(); index++)
    {
        if (!stackChar.empty() && s.at(index) == stackChar.top())
        {
            stackChar.pop();
        }
        else
        {
            stackChar.push(s.at(index));
        }
    }

    while (!stackChar.empty())
    {
        result += stackChar.top();
        stackChar.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}
