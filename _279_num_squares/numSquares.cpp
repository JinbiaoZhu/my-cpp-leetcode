#include "numSquares.h"
#include"utils.h"
#include"vector"

using namespace std;

int numSquares(int n)
{
    if (n == 1)
    {
        return 1;
    }

    int bagSize = n;
    int numType = n;
    vector<int> nums(numType, 0);
    for (int i = 0; i < numType; i++)
    {
        nums[i] = i * i;
    }

    // 1. 确定动态规划数组 dp[i] 表示目标数值为 i 条件下的完全平方数数量是 dp[i]
    vector<int> dp(bagSize + 1, 0);

    // 3. 确定动态规划初始化: dp[0] = 0; dp[i] = 100000000 这是题目中的最大值了
    dp[0] = 0;
    for (int i = 1; i < dp.size(); i++)
    {
        dp[i] = 100000000;
    }

    // 4. 确定动态规划的遍历方式: 先数值遍历, 再遍历平方数
    for (int i = 1; i <= bagSize; i++)
    {
        for (int j = 0; j < numType; j++)
        {
            if (i -j*j>=0 && dp[i-j*j]<=100000000)
            {
                // 2. 确定动态规划递推公式: dp[i] = min( dp[i], dp[i-j*j]+1 )
                dp[i] = min(dp[i], dp[i - nums[j]] + 1);
            }
        }
    }

    // 5. 人工进行数值模拟
    print_vector(dp);

    return dp[bagSize];
}
