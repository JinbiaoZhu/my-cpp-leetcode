#include "minCostClimbingStairs.h"
#include<vector>
#include<iostream>

using namespace std;

int minCostClimbingStairs(vector<int>& cost)
{
    // 1. 确定动态规划数组和其下标: dp[i] 表示爬到第 i 个台阶所需要的【最少】费用
    vector<int> dp;
    
    // 3. 确定递推初始化: dp[0]=0, dp[1]=0
    // 题目:"你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。"
    dp.push_back(0);
    dp.push_back(0);


    // 4. 确定递推顺序: 从前向后从左向右遍历
    for (int i = 2; i < cost.size()+1; i++)
    {
        // 2. 确定递推公式: dp[i]= min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2])
        // 注意是【最少】费用
        dp.push_back(
            min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
        );
    }

    // 5. 确定自己推演顺序: dp[0]=0, dp[1]=0, dp[2]=1, dp[3]=2, dp[4]=2, ...
    for (int i = 0; i < dp.size(); i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;

    return dp[dp.size() - 1];
}
