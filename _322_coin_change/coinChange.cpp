#include "coinChange.h"
#include"utils.h"
#include<math.h>

using namespace std;

int coinChange(vector<int>& coins, int amount)
{
    int bagSize = amount;
    int coinType = coins.size();

    // 1. 确定动态规划数组 dp[j] 表示数值是 j 情况下的最小组合数量是 dp[j]
    vector<int> dp(bagSize + 1, 0);

    // 3. 确定动态规划初始化: dp[0] = 0, dp[j] = INT_MAX (在 VS 2022 可以用 INFINITY 表示)
    dp[0] = 0;
    for (int i = 1; i < dp.size(); i++)
    {
        dp[i] = 2 << 10;
    }

    // 4. 确定动态规划的遍历方式: 完全背包问题, 如果求排列数就是外层 for 遍历背包, 内层 for 循环遍历物品.
    for (int i = 1; i <= bagSize; i++)
    {
        for (int j = 0; j < coinType; j++)
        {
            if (i-coins[j]>=0 && dp[i - coins[j]] != 2 << 10)
            {
                // 2. 确定动态规划的递推公式: dp[j] = min(dp[j], dp[j-coins[i]]+1) 
                //    "只需要加上一个钱币 coins[i] 即 dp[j - coins[i]] + 1 就是 dp[j] "
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    // 5. 人工模拟数值结果
    print_vector(dp);

    if (dp[bagSize] == 2 << 10)
    {
        return -1;
    }
    else 
    {
        return dp[bagSize];
    }
}
