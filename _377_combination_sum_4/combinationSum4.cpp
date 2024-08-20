#include"combinationSum4.h"
#include"utils.h"

using namespace std;

int combinationSum4(vector<int>& nums, int target) 
{
	int bagWise = target;
	int objectType = nums.size();

	// 1. ȷ����̬�滮���� dp ,���� dp[i] ��ʾ����Ϊ i �ı������Բ�����������
	vector<int> dp(target + 1, 0);

	// 3. ȷ����̬�滮�ĳ�ʼ��: dp[0] = 1; ����ȫ��Ϊ 0;
	dp[0] = 1;

	// 4. ȷ����̬�滮�ı���˳��: �ȱ�������, �ٱ�������, ���߶����������
	for (int j = 0; j <= target; j++)
	{
		for (int i = 0; i < objectType; i++)
		{
			// 2. ȷ����̬�滮�ĵ��ƹ�ʽ: dp[j] += dp[j-nums[i]];
			if (j >= nums[i] && dp[j] + dp[j - nums[i]] < (2 << 16))
			{
				dp[j] += dp[j - nums[i]];
			}
		}
	}

	// 5. �˹���ֵģ��
	print_vector(dp);

	return dp[bagWise];
}