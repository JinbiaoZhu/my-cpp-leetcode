#include "combinationSum2.h"
#include<algorithm>

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    vector<vector<int>> total_result;
    vector<int> path;
    int current_sum = 0; 
    int startIndex = 0;
    vector<bool> isUsed(candidates.size(), false);
    sort(candidates.begin(), candidates.end());
    backtrack(total_result, path, candidates, target, current_sum, startIndex, isUsed);
    return total_result;
}

// 确定回溯函数的输入输出
void backtrack(
    vector<vector<int>>& total_result, vector<int>& path, vector<int>& candidates,
    int target, int current_sum, int startIndex,
    vector<bool> isUsed
) 
{
    // 确定回溯函数的终止条件
    if (current_sum>target)
    {
        return;
    }
    if (current_sum == target)
    {
        total_result.push_back(path);
        return;
    }

    // 确定回溯函数的逻辑
    for (int i = startIndex; i < candidates.size(); i++)
    {
        if (i>=1 && candidates[i] == candidates[i-1] && isUsed[i-1]==false)
        {
            continue;
        }
        current_sum += candidates.at(i);
        path.push_back(candidates.at(i));
        isUsed[i] = true;
        backtrack(total_result, path, candidates, target, current_sum, i + 1, isUsed );
        isUsed[i] = false;
        path.pop_back();
        current_sum -= candidates.at(i);
    }
}