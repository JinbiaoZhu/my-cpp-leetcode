#pragma once
#include<vector>

using namespace std;

vector<vector<int>> combine(int n, int k);
void backtracking(int n, int k, int startIndex, vector<vector<int>>& total_result, vector<int>& path);