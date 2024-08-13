#include "largestSumAfterKNegations.h"
#include<algorithm>

using namespace std;

int largestSumAfterKNegations(vector<int>& nums, int k)
{
	// 1. 
	sort(nums.begin(),nums.end());

	// 2.
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] < 0) 
		{
			nums[i] = -nums[i];
			k--;
			if (k == 0)
			{
				return sum_of_vector(nums);
			}
		}
	}

	int min_index = min_value(nums);

	for (int i = k; i > 0; i--)
	{
		nums[min_index] = -nums[min_index];
	}
	return sum_of_vector(nums);
}

int sum_of_vector(vector<int> nums) 
{
	int result = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		result += nums[i];
	}
	return result;
}

int min_value(vector<int> nums)
{
	int temp_min = nums[0];
	int temp_index = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] <= temp_min)
		{
			temp_min = nums[i];
			temp_index = i;
		}
	}
	return temp_index;
}
