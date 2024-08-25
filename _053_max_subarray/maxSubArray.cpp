#include "maxSubArray.h"
#include <iostream>

using namespace std;

int maxSubArray(vector<int>& nums) {

    int sum = 0;
    int max_val = nums[0];

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum > max_val){
            max_val = sum;
        }

        if (sum <= 0){
            sum = 0;
        }
    }

    return max_val;
}

int maxSubArray_dp_version(vector<int>& nums)
{
    int numsLength = nums.size();

    if (numsLength == 0)
    {
        return 0;
    }

    // 1. dp[i] 表示包括下标 i 也即是以 nums[i] 结尾的最大子序列和
    // 3. dp[0] = nums[0];
    vector<int> dp(numsLength, 0);
    dp[0] = nums[0];

    // 4. 从小到大, 从前向后
    for (int i = 1; i < numsLength; i++)
    {
        // 2. dp[i] = max(
        //         dp[i-1] + nums[i],  // 表示新加入的数值;
        //         nums[i]             // 表示中断了, 重新开始
        //     )
        dp[i] = max(
            dp[i - 1] + nums[i],
            nums[i]
        );
    }

    // 5. 人工数值模拟
    for (int i : dp) { cout << i << " "; }
    cout << endl;

    // 6. 输出选取 dp 数组的最大值
    int current_max = dp[0];
    for (int i = 1; i < dp.size(); i++)
    {
        if (dp[i] > current_max)
        {
            current_max = dp[i];
        }
    }

    return current_max;
}
