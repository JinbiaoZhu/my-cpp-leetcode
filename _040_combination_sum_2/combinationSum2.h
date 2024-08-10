#pragma once
#include<vector>

using namespace std;

vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
void backtrack(
    vector<vector<int>>& total_result, vector<int>& path, vector<int>& candidates,
    int target, int current_sum, int startIndex,
    vector<bool> isUsed
);