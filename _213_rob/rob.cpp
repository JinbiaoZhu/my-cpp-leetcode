#include "rob.h"
#include"utils.h"

int rob(vector<int>& nums)
{
	if (nums.size() == 0)
	{
		return 0;
	}
	if (nums.size() == 1)
	{
		return nums[0];
	}

	int result_left = dynamicPlanning(nums, 0, nums.size() - 2);
	int result_right = dynamicPlanning(nums, 1, nums.size() - 1);

	return max(result_left, result_right);
}

int dynamicPlanning(vector<int>& nums, int left_pointer, int right_pointer) 
{
	if (left_pointer == right_pointer)
	{
		return nums[left_pointer];
	}

	// 1. ȷ����̬�滮���� dp[i] �ĺ������ڵ� 1 �����䵽�� i ���������͵��������ֵ
	vector<int> dp(nums.size(), 0);

	// 3. ȷ����̬�滮��ʼ��: dp[0] = nums[0]; dp[1] = max(dp[0], nums[0]);
	dp[left_pointer] = nums[left_pointer];
	dp[left_pointer + 1] = max(nums[left_pointer + 1], dp[left_pointer]);

	// 4. ȷ����̬�滮����˳��: ��ǰ�����С�������
	for (int i = left_pointer+2; i <= right_pointer; i++)
	{
		// 2. ȷ����̬�滮���ƹ�ʽ: dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
	}
	
	// 5. �˹�ģ����ֵ
	print_vector(dp);

	return dp[right_pointer];
}
