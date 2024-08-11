#pragma once
#include<vector>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums);
void backtrack(vector<vector<int>>& result, vector<int>& path, vector<int>& nums, int startIndex);