#include "solveNQueens.h"

int totalNQueens(int n)
{
	vector<vector<string>> result;
	vector<string> single_solution = { unsigned(n), string(unsigned(n), '.') };
	int current_row = 0;
	backtrack(result, single_solution, n, current_row);
	return result.size();
}

void backtrack(vector<vector<string>>& result, vector<string>& single_solution, int n, int current_row)
{
	if (current_row == n)
	{
		result.push_back(single_solution);
		return;
	}

	for (int col = 0; col < n; col++)
	{
		if (isValid(single_solution, current_row, col, n))
		{
			single_solution[current_row][col] = 'Q';
			backtrack(result, single_solution, n, current_row + 1);
			single_solution[current_row][col] = '.';
		}
	}
}

bool isValid(vector<string> single_solution, int row, int col, int n)
{
	for (int i = 0; i < row; i++)
	{
		if (single_solution[i][col] == 'Q')
		{
			return false;
		}
	}

	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (single_solution[i][j] == 'Q')
		{
			return false;
		}
	}

	for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
	{
		if (single_solution[i][j] == 'Q')
		{
			return false;
		}
	}

	return true;
}