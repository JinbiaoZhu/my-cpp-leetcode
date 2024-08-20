#include"combinationSum4.h"
#include"utils.h"

using namespace std;

int combinationSum4(vector<int>& nums, int target) 
{
	int bagWise = target;
	int objectType = nums.size();

	// 1. 确定动态规划数组 dp ,其中 dp[i] 表示容量为 i 的背包可以产生的排列数
	vector<int> dp(target + 1, 0);

	// 3. 确定动态规划的初始化: dp[0] = 1; 其他全部为 0;
	dp[0] = 1;

	// 4. 确定动态规划的遍历顺序: 先遍历背包, 再遍历物体, 两者都是正向遍历
	for (int j = 0; j <= target; j++)
	{
		for (int i = 0; i < objectType; i++)
		{
			// 2. 确定动态规划的递推公式: dp[j] += dp[j-nums[i]];
			if (j >= nums[i] && dp[j] + dp[j - nums[i]] < (2 << 16))
			{
				dp[j] += dp[j - nums[i]];
			}
		}
	}

	// 5. 人工数值模拟
	print_vector(dp);

	return dp[bagWise];
}