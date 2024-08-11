#include "solveSudoku.h"

void solveSudoku(vector<vector<char>>& board)
{
	backtrack(board);
}

bool backtrack(vector<vector<char>>& board) 
{
	for (int row = 0; row < board.size(); row++)
	{
		for (int col = 0; col < board[0].size(); col++)
		{
			if (board[row][col] != '.')
			{
				continue;
			}
			
			for (char num = '1'; num <= '9'; num++)
			{
				if (isValid(board, row, col, num))
				{
					board[row][col] = num;
					if (backtrack(board))
					{
						return true;
					}
					board[row][col] = '.';
				}
			}

			return false;
		}
	}

	return true;
}

bool isValid(vector<vector<char>>& chessboard, int row, int col, char val) 
{
	for (int i = 0; i < 9; i++)
	{
		if (chessboard[row][i] == val)
		{
			return false;
		}
	}

	for (int j = 0; j < 9; j++)
	{
		if (chessboard[j][col] == val) 
		{
			return false;
		}
	}

	int start_row = (row / 3) * 3;
	int start_col = (col / 3) * 3;
	for (int i = start_row; i < start_row + 3; i++)
	{
		for (int j = start_col; j < start_col+3; j++)
		{
			if (chessboard[i][j] == val)
			{
				return false;
			}
		}
	}

	return true;
}
