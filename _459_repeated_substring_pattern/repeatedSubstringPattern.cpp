#include "repeatedSubstringPattern.h"

bool repeatedSubstringPattern(const string& s)
{
    if (s.size() == 0) 
    {
        return false;
    }
    int next[s.size()];
    getNext(next, s);
    int len = s.size();
    if (next[len - 1] != -1 && len % (len - (next[len - 1])) == 0) 
    {
        return true;
    }

    return false;
}

void getNext(int* next, const string& s)
{
    int j = 0;
    next[0] = j;

    for (int i = 1; i < s.size(); i++) 
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
    }
}
