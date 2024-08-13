#include "canJump.h"

bool canJump(vector<int>& nums)
{
	int current_max_range = 0;
	int predict_range = 0;

	for (int i = 0; i <= current_max_range; i++)
	{
		predict_range = i + nums[i];  // 记录当前状态下可达的最大状态
		current_max_range = max(predict_range, current_max_range);  // 还要跟实际的比较
		if (current_max_range>=nums.size()-1)
		{
			return true;
		}
	}
	return false;
}
