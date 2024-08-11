#include "permute.h"

vector<vector<int>> permute(vector<int>& nums)
{
	vector<vector<int>> result;
	vector<int> path;
	vector<bool> isUsed(nums.size(), false);
	backtrack(result, path, nums, isUsed);
	return result;
}

void backtrack(vector<vector<int>>& result, vector<int>& path, vector<int>& nums, vector<bool>isUsed) 
{
	if (path.size() == nums.size())
	{
		result.push_back(path);
		return;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		if (isUsed[i])
		{
			continue;
		}
		isUsed[i] = true;
		path.push_back(nums[i]);
		backtrack(result, path, nums, isUsed);
		path.pop_back();
		isUsed[i] = false;
	}
}
