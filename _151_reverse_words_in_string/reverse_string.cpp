#include "reverse_string.h"

string reverseWords(string s)
{

    /////////////////////////////////////////////////////////////////
    // // ʹ��˫ָ�뷨�������Ҫ�Ŀո�
    int fast = 0;
    int slow = 0;

    // // ����׸�����ǰ��Ŀո�
    while (s.size() > 0 && fast < s.size() && s[fast] == ' ') 
    {
        fast++;
    }

    // // �������֮��Ķ���ո�
    while (true)
    {
        if (fast >= s.size()) 
        {
            break;
        }
        else 
        {
            if (fast - 1 > 0 && s[fast - 1] == s[fast] && s[fast] == ' ')
            {
                continue;
            }
            else
            {
                s[slow] = s[fast];
            }
        }
        fast++;
        slow++;
    }

    // // ������һ�����ʵ����һ���ո�
    if (slow - 1 > 0 && s[slow - 1] == ' ') 
    {
        s.resize(slow - 1);
    }
    else 
    {
        s.resize(slow);
    }

    /////////////////////////////////////////////////////////////////
    // �������ַ���ת��˳��
    int left = 0;
    int right = s.size() - 1;

    while (true)
    {
        if (right < left) 
        {
            break;
        }
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        right--;
        left++;
    }

    /////////////////////////////////////////////////////////////////
    int start = 0;
    for (int i = 1; i <= s.size(); i++) 
    {
        if (i == s.size() || s[i] == ' ') 
        {
            {
                int left = start;
                int right = i - 1;

                while (true)
                {
                    if (right < left)
                    {
                        break;
                    }
                    char temp = s[left];
                    s[left] = s[right];
                    s[right] = temp;

                    right--;
                    left++;
                }
                start = i + 1;
            }
        }
    }

    return s;
}
