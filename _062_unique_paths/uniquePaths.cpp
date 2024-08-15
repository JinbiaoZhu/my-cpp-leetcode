#include"uniquePaths.h"
#include<vector>

using namespace std;


int uniquePaths(int m, int n)
{
	// 1. ȷ����̬�滮������±�: dp[i][j] ��ʾ�� (0,0) �� (i,j) λ�õ�����
	//    ���� 0 <= i <= m-1; 0 <= j <= n-1;
	vector<vector<int>> dp(m, vector<int>(n, 0));

	// 3. ȷ����̬�滮��ʼֵ; d[0][0] = 0; d[i][0] = 1; d[0][j] = 1;
	for (int row = 0; row < m; row++)
	{
		dp[row][0] = 1;
	}
	for (int col = 0; col < n; col++)
	{
		dp[0][col] = 1;
	}

	// 2. ȷ����̬�滮��������: d[i][j] = dp[i-1][j] + dp[i][j-1]
	// 4. ȷ����̬�滮�ı�������: ��ÿһ��ѭ��, ÿһ������ÿһ��ѭ��
	for (int row = 1; row < m; row++)
	{
		for (int col = 1; col < n; col++)
		{
			dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
		}
	}
	
	// 5. ��������: ʵ���Ͼ��Ƕ���ʽ����
	//    ����ʡ����

	return dp[m - 1][n - 1];
}