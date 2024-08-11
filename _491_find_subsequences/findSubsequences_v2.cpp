#include"findSubsequences_v2.h"
#include<unordered_set>

using namespace std;

vector<vector<int>> findSubsequences_v2(vector<int>& nums) 
{
	vector<vector<int>> result;
	vector<int> path;
	int startIndex = 0;
	backtrack_v2(result, path, nums, startIndex);
	return result;
}

void backtrack_v2(vector<vector<int>>& result, vector<int>& path, vector<int>& nums, int startIndex) 
{
	if (path.size() > 1)
	{
		result.push_back(path);
	}

	unordered_set<int> map;
	for (int i = startIndex; i < nums.size(); i++)
	{
		if ((!path.empty() && nums[i] < path.back()) || 
			(map.find(nums[i]) != map.end())) 
		{
			continue;
		}
		map.insert(nums[i]);
		path.push_back(nums[i]);
		backtrack_v2(result, path, nums, i + 1);
		path.pop_back();
	}
}
