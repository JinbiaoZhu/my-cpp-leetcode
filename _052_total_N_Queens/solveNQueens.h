#pragma once
#include<vector>
#include<string>

using namespace std;

int totalNQueens(int n);
void backtrack(vector<vector<string>>& result, vector<string>& single_solution, int n, int current_row);
bool isValid(vector<string> single_solution, int row, int col, int n);