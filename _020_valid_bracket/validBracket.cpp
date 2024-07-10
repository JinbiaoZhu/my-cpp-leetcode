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
        // ���������, �����ջ�Ĵ���
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
            return false;   // ��ûƥ����Ϳ�ջ, ����ջ����������ڵ�ǰ�ַ�
        }
        else 
        {
            bracketStack.pop();  // ƥ�䵽����, ֱ�ӳ�ջ
        }
    }


    return bracketStack.empty();
}
