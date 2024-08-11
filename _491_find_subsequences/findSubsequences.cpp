#include "findSubsequences.h"

vector<vector<int>> findSubsequences(vector<int>& nums)
{
	filter_decrease_element(nums);
	vector<vector<int>> result;
	vector<int> path;
	int startIndex = 0;
	vector<bool> isUsed(nums.size(), false);
	backtrack(result, path, nums, startIndex, isUsed);
	filter_single_vector(result);
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
		if (i>0&&nums[i]==nums[i-1]&&isUsed[i]==false)
		{
			continue;
		}
		isUsed[i] = true;
		path.push_back(nums[i]);
		if (path.size()<=1)
		{
			continue;
		}
		result.push_back(path);
		backtrack(result, path, nums, i + 1, isUsed);
		path.pop_back();
		isUsed[i] = false;
	}
}

void filter_single_vector(vector<vector<int>>& result) 
{
	for (int i = 0; i < result.size(); i++)
	{
		if (i > 0 && result[i].size() <= 1)
		{
			result.erase(result.begin() + i);
		}
	}
}

void filter_decrease_element(vector<int>& nums) 
{
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > 0 && nums[i - 1] > nums[i]) 
		{
			nums.erase(nums.begin() + i);
		}
	}
}
