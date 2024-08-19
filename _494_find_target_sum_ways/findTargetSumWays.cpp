#include "findTargetSumWays.h"
#include<math.h>
#include<iostream>

using namespace std;

// 假设左边都是正号, 右边都是负号, 且提取了公共的负号, 所以左边部分和右边部分都是正的
// 左边部分 - 右边部分 = target
// 左边部分 + 右边部分 = sum
// 左边部分 = (target + sum) / 2
// 转化成 01 背包问题: 包容量 = 左边部分, 石头重量 = nums, 石头价值 = nums


int findTargetSumWays(vector<int>& nums, int target)
{
	if (nums.size() < 1)
	{
		return 0;
	}
	else  // nums.size() >= 1
	{
		int sum = sum_of_vector(nums);
		if (abs(target)>sum)
		{
			return 0;
		}
		else
		{
			if ((target + sum) % 2 ==1)
			{
				// 例如 sum 是 5 , target 是 2 的话其实就是无解的
				// 5 是奇数, 说明 nums 数组里面至少存在一个奇数, 那么 target 就不可能是偶数
				// 奇数加减奇数等于偶数, 偶数加减偶数等于偶数, 奇数加减偶数还是奇数
				return 0;
			}
			else
			{
				int left_part = (target + sum) / 2;
				// 1. 确定动态规划数组: dp[i] 表示包容量为 i 条件下存在 dp[i] 中方法
				// 3. 确定动态规划的初始化形式: dp[0]=1 表示包容量为 0 条件下默认存在 1 中方法
				vector<int> dp(left_part + 1, 0);
				dp[0] = 1;

				// 4. 确定动态规划的递推方式: 数组正向遍历, 包重量反向遍历
				for (int i = 0; i < nums.size(); i++)
				{
					for (int j = left_part; j >= nums[i]; j--)
					{
						// 2. 确定动态规划数组的递推式: dp[j] += dp[j - nums[i]] 其中 j <= nums[i]
						dp[j] += dp[j - nums[i]];
					}
				}
				// 5. 手动数值模拟
				for (int i = 0; i < dp.size(); i++)
				{
					cout << dp[i] << " ";
				}
				cout << endl;

				return dp[left_part];
			}
		}
	}
}


int sum_of_vector(vector<int>& nums) 
{
    int result = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		result += nums[i];
	}
	return result;
}