#include "combinationSum.h"
#include<algorithm>

using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	vector<vector<int>> result; vector<vector<int>> new_result;
	vector<int> path;
	int sum = 0;
	int startIndex = 0;
	backtrack(result, path, candidates, target, sum, startIndex);
	for (int i = 0; i < result.size(); i++)
	{
		if (sum_of_vector(result[i]) == target)
		{
			new_result.push_back(result[i]);
		}
	}
	return new_result;
}

// 确定回溯的输入和输出
void backtrack(vector<vector<int>>& result, vector<int>& path, vector<int>& candidates, int target, int sum, int startIndex) 
{
	// 确定回溯终止条件
	if (sum>target)
	{
		return;
	}
	if (sum==target)
	{
		for (int i = 0; i < result.size(); i++)
		{
			sort(result[i].begin(), result[i].end());
			sort(path.begin(), path.end());
			if (result[i] == path)
			{
				return;
			}
		}
		result.push_back(path);
		return;
	}

	// 确定回溯逻辑
	for (startIndex; startIndex < candidates.size(); startIndex++)
	{
		path.push_back(candidates[startIndex]);
		sum += candidates[startIndex];
		backtrack(result, path, candidates, target, sum, startIndex);
		sum -= candidates[startIndex];
		path.pop_back();
	}
}

int sum_of_vector(vector<int> nums) 
{
	int temp = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		temp += nums[i];
	}
	return temp;
}