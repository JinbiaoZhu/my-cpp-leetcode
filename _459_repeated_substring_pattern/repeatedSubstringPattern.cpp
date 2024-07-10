#include "repeatedSubstringPattern.h"
#include <vector>
#include<iostream>

using namespace std;

bool repeatedSubstringPattern(const string& s)
{
    if (s.size() == 0) 
    {
        return false;
    }

    vector<int> next(s.size());
    
    getNext(next, s);
    // 打印 next 向量的内容
    std::cout << "next vector: ";
    for (int i : next) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    int len = s.size();
    cout << "The length of the string is " << len << endl;

    int last_number = next[static_cast<std::vector<int, std::allocator<int>>::size_type>(len) - 1];
    
    if (last_number != 0 && len % (len - (last_number)) == 0)
    {
        return true;
    }

    return false;
}

void getNext(vector<int>& next, const string& s)
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
