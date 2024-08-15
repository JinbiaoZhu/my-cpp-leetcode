#include "numTrees.h"
#include<vector>

using namespace std;

int numTrees(int n)
{
    // 1. 确定动态规划的数组和下标: dp[i] 表示 i 个数可以产生 dp[i] 个二叉搜索树
    vector<int> dp(n+1);

    // 3. 确定动态规划的初始化
    dp[0] = 1;

    // 2. 确定动态规划的递推表达式
    for (int i = 1; i <= n; i++)
    {
        // 4. 确定动态规划的遍历方式: 从前向后, 从左向右遍历
        for (int j = 1; j <= i; j++)
        {
            dp[i] += dp[j-1] * dp[i - j];
        }
    }
   
    // 5. 确定人工数值模拟
    //    省略
    return dp[n];
}
