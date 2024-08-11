#pragma once
#include<vector>

using namespace std;

vector<vector<int>> findSubsequences_v2(vector<int>& nums);
void backtrack_v2(vector<vector<int>>& result, vector<int>& path, vector<int>& nums, int startIndex);

