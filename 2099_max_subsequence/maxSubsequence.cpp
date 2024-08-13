#include "maxSubsequence.h"

vector<int> maxSubsequence(vector<int>& nums, int k)
{
    int num_to_delete = nums.size() - k;

	for (int i = 0; i < num_to_delete; i++)
	{
		int index = min_value_index(nums);
		nums.erase(nums.begin() + index);
	}

	return nums;
}

int min_value_index(vector<int> nums) 
{
	int temp_min = nums[0];
	int temp_index = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		if (temp_min >= nums[i])
		{
			temp_min = nums[i];
			temp_index = i;
		}
	}
	return temp_index;
}