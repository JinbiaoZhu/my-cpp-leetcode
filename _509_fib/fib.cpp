#include"fib.h"
#include<vector>

#include<iostream>

using namespace std;

int fib(int n)
{
	// 1. ȷ����̬�滮�����Լ��±�ĺ���: dp �洢쳲�������, �±� i ��ʾλ��
	vector<int> dp;

	// 3. ȷ����̬�滮����ĳ�ʼ�� F(0) = 0; F(1) = 1;
	if (n<=1)
	{
		return n;
	}

	dp.push_back(0);
	dp.push_back(1);
	// 4. ȷ������˳��: ��ǰ������
	for (int i = 2; i <= n; i++)
	{
		// 2. ȷ�����ƹ�ʽ: F(n) = F(n - 1) + F(n - 2)
		dp.push_back(dp[i - 1] + dp[i - 2]);
	}
	
	// 5. �����Ƶ���̬�滮����: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89
	for (int i = 0; i < dp.size(); i++)
	{
		cout << dp[i] << " ";
	}
	cout << endl;

	return dp[dp.size() - 1];
}