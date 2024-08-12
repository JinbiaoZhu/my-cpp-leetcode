#include "findContentChildren.h"
#include<algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s)  // g 表示孩子的胃口值 s 表示饼干的大小
{
    int result = 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int s_index = s.size() - 1;

    for (int i = g.size() - 1; i >= 0 ; i--)
    {
        if (s_index<0)
        {
            break;
        }
        if (s[s_index] >= g[i])
        {
            result++;
            s_index--;
        }
    }
    
    return result;
}

int findContentChildren_v2(vector<int>& g, vector<int>& s)
{
    if (g.size()==0||s.size()==0)
    {
        return NULL;
    }
    int result = 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int s_index = 0;

    for (int i = 0; i < g.size(); i++)
    {
        if (s_index>s.size()-1)
        {
            break;
        }
        if (s[s_index] >= g[i])
        {
            result++;
            s_index++;
        }
    }

    return result;
}


