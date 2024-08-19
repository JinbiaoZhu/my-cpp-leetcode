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

		// 1. ȷ����̬�滮����: dp[i] ��ʾ�ܳ���Ϊ i �ı���Ŀǰ�������� dp[i] ������
		// 3. ȷ����̬�滮�����ʼ��: ȫ 0 ,��ʾ: �ܳ���Ϊ i �ı���Ŀǰ�������� 0 ������
		vector<int> dp(target + 1, 0);

		// 2. ȷ����̬�滮����ʽ: dp[j] = max(dp[i], dp[j - stones[i]] + stones[i]);
		// 4. ȷ����̬�滮����˳��: �������鷽��, ��ǰ˳�����ʯͷ, ��������������
		for (int i = 0; i < stones.size(); i++)
		{
			for (int j = target; j >= stones[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
			}
		}

		// 5. �˹�ģ����ֵ���
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
