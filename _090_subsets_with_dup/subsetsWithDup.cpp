#include "subsetsWithDup.h"
#include"algorithm"

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
	vector<vector<int>> result;
	vector<int> path;
	int startIndex = 0;
	vector<bool> isUsed(nums.size(), false);
	sort(nums.begin(), nums.end());
	backtrack(result, path, nums, startIndex, isUsed);
	result.push_back(vector<int>{});
	return result;
}

void backtrack(vector<vector<int>>& result, vector<int>& path, vector<int>& nums, int startIndex, vector<bool>& isUsed)
{
	if (startIndex>nums.size())
	{
		return;
	}

	for (int i = startIndex; i < nums.size(); i++)
	{
		if (i > 0 && nums[i] == nums[i - 1] && isUsed[i - 1]==false) 
		{
			continue;
		}
		isUsed[i] = true;
		path.push_back(nums[i]);
		result.push_back(path);
		backtrack(result, path, nums, i + 1, isUsed);
		path.pop_back();
		isUsed[i] = false;
	}
}