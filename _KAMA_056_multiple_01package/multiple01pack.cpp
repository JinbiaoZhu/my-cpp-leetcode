#include "multiple01pack.h"
#include"utils.h"

int multiple01pack(vector<int>& weights, vector<int>& values, vector<int>& nums, int capacity)
{
    int numType = weights.size();

    // 1. 确定动态规划数组 dp[i] 表示容量是 i 的情况下最大的价值是 dp[i]
    // 3. 确定动态规划数组初始化, 全 0 即可
    vector<int> dp(capacity + 1, 0);

    // 4. 确定动态规划的遍历顺序: 遍历物品 (正向) 再遍历容量 (逆向)
    for (int i = 0; i < numType; i++) 
    {
        for (int j = capacity; j >= weights[i]; j--)
        {
            for (int k = 1; k <= nums[i] && j - k * weights[i] >= 0; k++)
            {
                // 2. 确定动态规划的递推公式: dp[i] = max(dp[i], dp[i - k * weights[j]] + k * values[j])
                dp[j] = max(dp[j], dp[j - k * weights[i]] + k * values[i]);
            }
        }
    }

    // 5. 人工模拟数值结果
    print_vector(dp);

    return dp[capacity];
}
