#include "findMaxForm.h"
#include<iostream>

using namespace std;

int findMaxForm(vector<string>& strs, int m, int n)
{
	// 1. 确定动态规划的数组: dp[i][j] 表示最大子集中存在 i 个 0 和 j 个 1 的元素个数
	// 3. 确定动态规划的初始化: 01 背包问题初始化全 0
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < strs.size(); i++)
	{
		// 0. 这里统计 zeroNum 和 onesNum 的目的就是统计出 weight 
		int zeroNum = 0, onesNum = 0;
		for (int j = 0; j < strs[i].size(); j++)
		{
			if (strs[i][j] == '0')
			{
				zeroNum++;
			}
			else
			{
				onesNum++;
			}
		}

		// 4. 确定动态规划遍历: 对 m 和 n 从小到大遍历
		for (int i = m; i >= zeroNum; i--)
		{
			for (int j = n; j >= onesNum; j--)
			{
				// 2. 确定动态规划递推公式: dp[i][j] = max(dp[i][j], dp[i-zeroNum][j-onesNum]+1)
				dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - onesNum] + 1);
			}
		}
	}

	// 5. 人工数值模拟
	//for (vector<int> i : dp) 
	//{
	//	for (int j: i)
	//	{
	//		cout << j << " ";
	//	}
	//	cout << endl;
	//}

	return dp[m][n];
}
