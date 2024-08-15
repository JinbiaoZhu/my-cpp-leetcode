#include"fib.h"
#include<vector>

#include<iostream>

using namespace std;

int fib(int n)
{
	// 1. 确定动态规划数组以及下标的含义: dp 存储斐波那契数, 下标 i 表示位置
	vector<int> dp;

	// 3. 确定动态规划数组的初始化 F(0) = 0; F(1) = 1;
	if (n<=1)
	{
		return n;
	}

	dp.push_back(0);
	dp.push_back(1);
	// 4. 确定遍历顺序: 从前向后遍历
	for (int i = 2; i <= n; i++)
	{
		// 2. 确定递推公式: F(n) = F(n - 1) + F(n - 2)
		dp.push_back(dp[i - 1] + dp[i - 2]);
	}
	
	// 5. 举例推导动态规划数组: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89
	for (int i = 0; i < dp.size(); i++)
	{
		cout << dp[i] << " ";
	}
	cout << endl;

	return dp[dp.size() - 1];
}