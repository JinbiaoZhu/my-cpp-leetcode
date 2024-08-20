#include "climb.h"
#include"utils.h"

int climb(vector<int>& nums, int target)
{
    // 1. 确定动态规划数组: dp[i] 表示楼梯是 i 阶的情况下 dp[i] 的组合数
    vector<int> dp(target + 1, 0);

    // 3. 确定动态规划的初始化: dp[0] = 1
    dp[0] = 1;

    // 4. 确定动态规划的遍历方式: 先楼梯阶数再物体顺序
    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (i - nums[j] >= 0)
            {
                // 2. 确定动态规划递推公式: dp[i] += dp[i-nums[j]]
                dp[i] += dp[i - nums[j]];
            }
        }
    }
    
    // 5. 人工数值模拟
    print_vector(dp);

    return dp[target];
}
