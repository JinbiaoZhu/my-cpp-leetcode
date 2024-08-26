#pragma once
#include <vector>
#include <list>

using namespace std;

void dfs_adj_table(vector<list<int>>& graph, vector<vector<int>>& result, vector<int>& path, int x, int n);

void main_adj_table();