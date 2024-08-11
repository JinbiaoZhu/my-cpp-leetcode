#pragma once
#include<vector>

using namespace std;

vector<vector<int>> permuteUnique(vector<int>& nums);
void backtrack(vector<vector<int>>& result, vector<int>& path, vector<int>& nums, vector<bool>& isUsed);