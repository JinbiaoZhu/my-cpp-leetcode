#include "reverse_string.h"

string reverseWords(string s)
{

    /////////////////////////////////////////////////////////////////
    // // 使用双指针法清除不必要的空格
    int fast = 0;
    int slow = 0;

    // // 清除首个单词前面的空格
    while (s.size() > 0 && fast < s.size() && s[fast] == ' ') 
    {
        fast++;
    }

    // // 清楚单词之间的多余空格
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

    // // 清除最后一个单词的最后一个空格
    if (slow - 1 > 0 && s[slow - 1] == ' ') 
    {
        s.resize(slow - 1);
    }
    else 
    {
        s.resize(slow);
    }

    /////////////////////////////////////////////////////////////////
    // 对整个字符串转换顺序
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
