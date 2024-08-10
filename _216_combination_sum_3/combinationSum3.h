#pragma once
#include<vector>

using namespace std;

vector<vector<int>> combinationSum3(int k, int n);
void backtrack(vector<int>& single_path, vector<vector<int>>& total_result, int k, int n, int startIndex);
int vector_sum(vector<int> nums);