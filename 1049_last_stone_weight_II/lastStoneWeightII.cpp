#include "lastStoneWeightII.h"
#include<iostream>

using namespace std;

int lastStoneWeightII(vector<int>& stones)
{
	if (stones.size()<=1)
	{
		return stones[0];
	}
	else
	{
		int sum = sum_of_vector(stones);
		int target = sum / 2;

		// 1. 确定动态规划数组: dp[i] 表示总承重为 i 的背包目前最大承重了 dp[i] 的重量
		// 3. 确定动态规划数组初始化: 全 0 ,表示: 总承重为 i 的背包目前最大承重了 0 的重量
		vector<int> dp(target + 1, 0);

		// 2. 确定动态规划递推式: dp[j] = max(dp[i], dp[j - stones[i]] + stones[i]);
		// 4. 确定动态规划遍历顺序: 滚动数组方法, 向前顺序遍历石头, 向后逆序遍历重量
		for (int i = 0; i < stones.size(); i++)
		{
			for (int j = target; j >= stones[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
			}
		}

		// 5. 人工模拟数值结果
		for (int i = 0; i < dp.size(); i++)
		{
			cout << dp[i] << " ";
		}
		cout << endl;

		return sum - dp[target] - dp[target];
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
