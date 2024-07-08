#include "strStr.h"
#include<vector>

void getNext(int* next, const string& s)
{
    // 这里使用不减一的方法

    int j = 0;
    next[0] = j;

    int i = 1;
    while (i < s.size()) 
    {
        while (j >= 1 && s[i] != s[j]) 
        {
            j = next[j - 1];
        }
        if (s[i] == s[j]) 
        {
            j++;
        }
        next[i] = j;
        i++;
    }
}

int strStr(string haystack, string needle)
{
    
    if (needle.size() == 0) { return 0; }

    vector<int> next(needle.size());

    getNext(&next[0], needle);

    int j = 0;
    for (int index = 0; index < haystack.size(); index++)
    {
        while (j >= 1 && haystack[index] != needle[j]) 
        {
            j = next[static_cast<std::vector<int, std::allocator<int>>::size_type>(j) - 1];
        }

        if (haystack[index] == needle[j]) 
        {
            j++;
        }
        if (j == needle.size()) 
        {
            return (index - needle.size() + 1);
        }
    }
    return -1;
}
