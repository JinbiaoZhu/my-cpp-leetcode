#include "canPartition.h"

bool canPartition(vector<int>& nums)
{
    if (nums.size()<=1)
    {
        return false;
    }
    else
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2 == 1)
        {
            return false;
        }
        else
        {
            int target = sum / 2;
            int bag_weight = 100 * 200 / 2 + 1;

            vector<int> weight = nums;
            vector<int> values = nums;

            // 1. 确定动态规划 dp 数组: dp[i] 表示当背包重量为 i 时可以背得的最大重量是 dp[i]
            // 3. 确定动态规划初始化: dp[i] 可以全为 0 表示没有物体放入背包的情况下背包背的最大重量是 0
            vector<int> dp(bag_weight, 0);

            // 4. 确定动态规划的遍历: 对物体是正向顺序, 对重量是逆向顺序
            for (int i = 0; i < nums.size(); i++)
            {
                for (int j = target; j >= weight[i]; j--)
                {
                    // 2. 确定动态规划迭代公式: dp[i] = max( dp[i-1] , dp[j-weight[i]]+value[i] );
                    dp[j] = max(dp[j], dp[j- weight[i]] + values[i]);
                }
            }
            
            if (dp[target] == target)
            {
                return true;
            }
            else
            {
                return false;
            }

        }
    }
}
