#include "climbStairs.h"
#include<vector>
#include<iostream>

using namespace std;

int climbStairs(int n)
{
    // 1. 确定动态规划数组和下标
    vector<int> dp;

    // 3. 确定动态规划的初始设置: dp[1] = 1; dp[2] = 2;
    if (n<=2)
    {
        return n;
    }
    else
    {
        dp.push_back(1);
        dp.push_back(2);
    }

    // 4. 确定遍历顺序: 从小到大, 从前向后
    for (int i = 3 - 1; i < n; i++)
    {
        // 2. 确定动态规划的递推公式: dp[i] = dp[i-1] + dp[i-2];
        dp.push_back(dp[i - 1] + dp[i - 2]);
    }
    
    // 5. 确定人工推演; dp[1]=1; dp[2]=2; dp[3]=3; dp[4]=5; dp[5]=8 (从 index 为 1 开始)
    for (int i = 0; i < dp.size(); i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;

    return dp[dp.size() - 1];
}
