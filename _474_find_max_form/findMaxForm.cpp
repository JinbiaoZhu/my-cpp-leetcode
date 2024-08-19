#include "findMaxForm.h"
#include<iostream>

using namespace std;

int findMaxForm(vector<string>& strs, int m, int n)
{
	// 1. ȷ����̬�滮������: dp[i][j] ��ʾ����Ӽ��д��� i �� 0 �� j �� 1 ��Ԫ�ظ���
	// 3. ȷ����̬�滮�ĳ�ʼ��: 01 ���������ʼ��ȫ 0
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < strs.size(); i++)
	{
		// 0. ����ͳ�� zeroNum �� onesNum ��Ŀ�ľ���ͳ�Ƴ� weight 
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

		// 4. ȷ����̬�滮����: �� m �� n ��С�������
		for (int i = m; i >= zeroNum; i--)
		{
			for (int j = n; j >= onesNum; j--)
			{
				// 2. ȷ����̬�滮���ƹ�ʽ: dp[i][j] = max(dp[i][j], dp[i-zeroNum][j-onesNum]+1)
				dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - onesNum] + 1);
			}
		}
	}

	// 5. �˹���ֵģ��
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
