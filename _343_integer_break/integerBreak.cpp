#include "integerBreak.h"
#include<vector>
#include<iostream>

using namespace std;

int integerBreak(int n)
{
    // 1. 确定动态规划的数组和下标
    //    dp[i] 表示第 i 个数的最大乘积
    vector<int> dp(n + 1, NULL);

    // 3. 确定动态规划的初始条件
    //    dp[2] =1 题目给定 i >= 2
    dp[2] = 1;

    // 4. 确定动态规划的遍历条件
    //    从前往后, 从小到大遍历
    for (int i = 3; i <= n; i++)
    {
        // 2. 确定动态规划的递推公式
        //    由于 i = j + (i-j) 所以取 max(j * dp[i - j], j * (i-j))
        //    由于 j = 1,2,...i-1 所以 dp[i] = max[ dp[i], max(j * dp[i - j], j * (i-j)) ]
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(
                dp[i], max(j*(i-j),j*dp[i-j])
            );
        }
    }

    // 5. 人工模拟验证
    //    略
    for (int i = 0; i < dp.size(); i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;

    return dp[dp.size()-1];
}
