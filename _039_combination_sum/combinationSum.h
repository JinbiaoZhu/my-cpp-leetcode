#pragma once
#include<vector>

using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target);
void backtrack(vector<vector<int>>& result, vector<int>& path, vector<int>& candidates, int target, int sum, int startIndex);
int sum_of_vector(vector<int> nums);