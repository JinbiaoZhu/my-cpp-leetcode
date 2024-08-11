#include "subsets.h"
#include<iostream>

vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> result;
	vector<int> path;
	int startIndex = 0;
	backtrack(result, path, nums, startIndex);
	result.push_back(vector<int>{});
	return result;
}


void backtrack(vector<vector<int>>& result, vector<int>& path, vector<int>& nums, int startIndex)
{
	if (startIndex>=nums.size())
	{
		return;
	}
	
	for (int i = startIndex; i < nums.size(); i++)
	{   
		int number = nums[i];
		path.push_back(number);
		result.push_back(path);
		backtrack(result, path, nums, i+1);
		path.pop_back();
	}
}