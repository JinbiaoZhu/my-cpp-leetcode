#include "findTargetSumWays.h"
#include<math.h>
#include<iostream>

using namespace std;

// ������߶�������, �ұ߶��Ǹ���, ����ȡ�˹����ĸ���, ������߲��ֺ��ұ߲��ֶ�������
// ��߲��� - �ұ߲��� = target
// ��߲��� + �ұ߲��� = sum
// ��߲��� = (target + sum) / 2
// ת���� 01 ��������: ������ = ��߲���, ʯͷ���� = nums, ʯͷ��ֵ = nums


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
				// ���� sum �� 5 , target �� 2 �Ļ���ʵ�����޽��
				// 5 ������, ˵�� nums �����������ٴ���һ������, ��ô target �Ͳ�������ż��
				// �����Ӽ���������ż��, ż���Ӽ�ż������ż��, �����Ӽ�ż����������
				return 0;
			}
			else
			{
				int left_part = (target + sum) / 2;
				// 1. ȷ����̬�滮����: dp[i] ��ʾ������Ϊ i �����´��� dp[i] �з���
				// 3. ȷ����̬�滮�ĳ�ʼ����ʽ: dp[0]=1 ��ʾ������Ϊ 0 ������Ĭ�ϴ��� 1 �з���
				vector<int> dp(left_part + 1, 0);
				dp[0] = 1;

				// 4. ȷ����̬�滮�ĵ��Ʒ�ʽ: �����������, �������������
				for (int i = 0; i < nums.size(); i++)
				{
					for (int j = left_part; j >= nums[i]; j--)
					{
						// 2. ȷ����̬�滮����ĵ���ʽ: dp[j] += dp[j - nums[i]] ���� j <= nums[i]
						dp[j] += dp[j - nums[i]];
					}
				}
				// 5. �ֶ���ֵģ��
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