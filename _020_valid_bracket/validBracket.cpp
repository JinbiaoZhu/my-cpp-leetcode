#include "validBracket.h"
#include<string>
#include<stack>

using namespace std;

bool isValid(string s)
{
    if (s.size() % 2 != 0) 
    {
        return false;
    }

    stack<char> bracketStack;

    for (int index = 0; index < s.size(); index++) 
    {
        // 对特殊符号, 输入堆栈的处理
        if (s.at(index) == '(') 
        {
            bracketStack.push(')'); 
        }
        else if (s.at(index) == '[')
        {
            bracketStack.push(']'); 
        }
        else if (s.at(index) == '{') 
        {
            bracketStack.push('}'); 
        }
        else if (bracketStack.empty() || bracketStack.top()!=s.at(index))
        {
            return false;   // 还没匹配完就空栈, 或者栈的最顶部不等于当前字符
        }
        else 
        {
            bracketStack.pop();  // 匹配到符号, 直接出栈
        }
    }


    return bracketStack.empty();
}
