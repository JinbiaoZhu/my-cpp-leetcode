#include "change.h"
#include"utils.h"

int change(int amount, vector<int>& coins)
{
    int bagWeight = amount;
    int coinType = coins.size();

    // 1. 确定动态规划的数组 dp[i] 表示在背包容量是 i 的情况下获得的最大价值是 dp[i]
    vector<int> dp(bagWeight + 1, 0);

    // 3. 确定动态规划的初始化: dp[0] = 1;
    dp[0] = 1;

    // 4. 确定动态规划的遍历顺序: 先正向遍历物体在正向遍历背包承重
    for (int i = 0; i < coinType; i++)
    {
        for (int j = coins[i]; j <= bagWeight; j++)
        {
            // 2. 确定动态规划的递推公式: dp[j] += dp[j-coins[i]];
            dp[j] += dp[j - coins[i]];
        }
    }

    print_vector(dp);

    return dp[bagWeight];
}
