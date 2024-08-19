#include "minimumDifference.h"
#include<math.h>
#include<iostream>

using namespace std;

int minimumDifference(vector<int>& nums)
{
	if (nums.size() <= static_cast<unsigned long long>(1) * 2)
	{
		return abs(nums[0] - nums[1]);
	}
	else
	{
		int mini = min_of_vector(nums);
		for (int i = 0; i < nums.size(); i++)
		{
			nums[i] += abs(mini);
		}


		int sum = sum_of_vector(nums);
		
		int target = sum / 2;
		
		// 1.
		vector<int> dp(sum, 0);

		// 2.
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = target; j >= nums[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
			}
		}

		for (int i = 0; i < dp.size(); i++)
		{
			cout << dp[i] << " ";
		}
		cout << endl;

		int A = dp[target];
		int B = sum - A;

		return abs(B - A);
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

int min_of_vector(vector<int>& nums) 
{
	int result = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] < result)
		{
			result = nums[i];
		}
	}
	return result;
}


