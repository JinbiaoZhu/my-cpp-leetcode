#include"uniquePaths.h"
#include<vector>

using namespace std;


int uniquePaths(int m, int n)
{
	// 1. 确定动态规划数组和下标: dp[i][j] 表示从 (0,0) 到 (i,j) 位置的条数
	//    其中 0 <= i <= m-1; 0 <= j <= n-1;
	vector<vector<int>> dp(m, vector<int>(n, 0));

	// 3. 确定动态规划初始值; d[0][0] = 0; d[i][0] = 1; d[0][j] = 1;
	for (int row = 0; row < m; row++)
	{
		dp[row][0] = 1;
	}
	for (int col = 0; col < n; col++)
	{
		dp[0][col] = 1;
	}

	// 2. 确定动态规划递推条件: d[i][j] = dp[i-1][j] + dp[i][j-1]
	// 4. 确定动态规划的遍历条件: 先每一行循环, 每一行内再每一列循环
	for (int row = 1; row < m; row++)
	{
		for (int col = 1; col < n; col++)
		{
			dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
		}
	}
	
	// 5. 自行推演: 实际上就是二项式定理
	//    这里省略了

	return dp[m - 1][n - 1];
}