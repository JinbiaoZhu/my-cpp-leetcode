#include "wordBreak.h"
#include"utils.h"

bool wordBreak(string s, vector<string>& wordDict)
{
    int bagSize = s.size();
    int wordNum = wordDict.size();

    // 1. 确定动态规划数组 dp[i] 表示字符串长度为 i 时候是否可以拆分成字典内部的单词
    vector<int> dp(bagSize + 1, false);

    // 3. 确定动态规划数组的初始化 dp[0] = true
    dp[0] = true;

    // 4. 确定动态规划的遍历顺序: 先字符长度再每个单词
    for (int i = 1; i <= bagSize; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i - j >= 0)
            {
                // 2. 确定动态规划递推表达式: dp[i] = true if (s.substr(i,j) in wordDict) && dp[i] == true
                string temp = s.substr(j, i - j);
                if (isInDict(temp, wordDict) && dp[j])
                {
                    dp[i] = true;
                }
            }
        }
    }

    // 5. 人工模拟数值结果
    print_vector(dp);

    return dp[bagSize];
}


bool isInDict(string& s, vector<string>& wordDict) 
{
    for (string _s : wordDict) 
    {
        if (s == _s)
        {
            return true;
        }
    }
    return false;
}
