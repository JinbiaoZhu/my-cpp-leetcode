#include "wiggleMaxLength.h"

int wiggleMaxLength(vector<int>& nums)
{
	if (nums.size() <= 1)
	{
		return nums.size();
	}

	int pre_difference = 0;
	int cur_difference = 0;
	int result = 1;

	for (int i = 0; i < nums.size()-1; i++)
	{
		cur_difference = nums[i] - nums[i+1];

		if ((pre_difference >= 0 && cur_difference < 0) || (pre_difference <= 0 && cur_difference > 0))
		{
			result++;
			pre_difference = cur_difference;
		}
	}

	return result;
}
