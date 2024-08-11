#include "permuteUnique.h"
#include<algorithm>

using namespace std;

vector<vector<int>> permuteUnique(vector<int>& nums)
{
	vector<vector<int>> result;
	vector<int> path;
	vector<bool> isUsed(nums.size(), false);
	sort(nums.begin(), nums.end());
	backtrack(result, path, nums, isUsed);
	return result;
}

void backtrack(vector<vector<int>>& result, vector<int>& path, vector<int>& nums, vector<bool>& isUsed) 
{
	if (path.size() == nums.size())
	{
		result.push_back(path);
		return;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		if (i >= 1 && nums[i] == nums[i - 1] && isUsed[i - 1] == false) 
		{
			continue;
		}
		if (isUsed[i])
		{
			continue;
		}

		path.push_back(nums[i]);
		isUsed[i] = true;
		backtrack(result, path, nums, isUsed);
		isUsed[i] = false;
		path.pop_back();
	}
}
