#include "rob.h"
#include"utils.h"

int rob(vector<int>& nums)
{
    int N = nums.size();

    // 1. 确定动态规划数组 dp[i] 表示在第 1 到第 i 个房间中可以偷盗的最大金额
    vector<int> dp(N, 0);

    if (N==1)
    {
        return nums[0];
    }
    else
    {
        // 3. 确定动态规划数组初始化: dp[0] = nums[0]; dp[1] = max(nums[0],nums[1])
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);

        // 4. 确定动态规划遍历顺序: 从左向右从小到大遍历
        for (int i = 2; i < N; i++)
        {
            // 2. 确定动态规划递推公式: dp[i] = max(
            //     dp[i-1] ----> 说明 dp[i-1] 被偷家了, 这家不能再偷了
            //     dp[i-2] + nums[i] ----> 说明 dp[i-2] 被偷家了, 这家可以接着偷   
            // )
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        // 5. 人工模拟数值结果
        print_vector(dp);

        return dp[N - 1];
    }
}
