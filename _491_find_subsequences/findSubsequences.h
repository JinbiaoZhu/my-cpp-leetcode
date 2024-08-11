#pragma once
#include<vector>

using namespace std;

vector<vector<int>> findSubsequences(vector<int>& nums);
void backtrack(vector<vector<int>>& result, vector<int>& path, vector<int>& nums, int startIndex, vector<bool>& isUsed);
void filter_single_vector(vector<vector<int>>& result);
void filter_decrease_element(vector<int>& nums);