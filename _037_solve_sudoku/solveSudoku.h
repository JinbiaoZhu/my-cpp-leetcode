#pragma once
#include<vector>

using namespace std;

void solveSudoku(vector<vector<char>>& board);
bool backtrack(vector<vector<char>>& board);
bool isValid(vector<vector<char>>& chessboard, int row, int col, char val);
