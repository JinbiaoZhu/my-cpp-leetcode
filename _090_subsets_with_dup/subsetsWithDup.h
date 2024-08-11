#pragma once
#include<vector>

using namespace std;

vector<vector<int>> subsetsWithDup(vector<int>& nums);
void backtrack(vector<vector<int>>& result, vector<int>& path, vector<int>& nums, int startIndex, vector<bool>& isUsed);