#include "dfs_v2.h"
#include <iostream>

using namespace std;

// 第一行包含两个整数 N 和 M，分别表示矩阵的行数和列数。 
// 后续 N 行，每行包含 M 个整数，表示矩阵中的每个单元格的高度。
int N_v2, M_v2;
int directions[4][2] = { -1,0,1,0,0,1,0,-1 };


void dfs_v2(vector<vector<int>>& grid, vector<vector<bool>>& isVisited, int x, int y)
{
	if (isVisited[x][y] == true || grid[x][y] == 0)
	{
		return;
	}

	isVisited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + directions[i][0];
		int ny = y + directions[i][1];

		if (nx < 0 || nx >= N_v2 || ny < 0 || ny >= M_v2)
		{
			continue;
		}

		if (grid[x][y] > grid[nx][ny])
		{
			continue;
		}

		dfs_v2(grid, isVisited, nx, ny);
	}

	return;
}

void main_dfs_v2()
{
	cin >> N_v2 >> M_v2;

	vector<vector<int>> grid(N_v2, vector<int>(M_v2, 0));
	for (int i = 0; i < N_v2; i++)
	{
		for (int j = 0; j < M_v2; j++)
		{
			cin >> grid[i][j];
		}
	}
	cout << "----------" << endl;

	for ( vector<int>& row : grid )
	{
		for ( int col : row )
		{
			cout << col << " ";
		}
		cout << endl;
	}
	cout << "----------" << endl;

	vector<vector<bool>> first(N_v2, vector<bool>(M_v2, false));
	vector<vector<bool>> second(N_v2, vector<bool>(M_v2, false));

	for (int i = 0; i < N_v2; i++)
	{
		dfs_v2(grid, first,i, 0);
		dfs_v2(grid, second, i, M_v2 - 1);
	}

	for (int j = 0; j < M_v2; j++)
	{
		dfs_v2(grid, first, 0, j);
		dfs_v2(grid, second, N_v2 - 1, j);
	}

	for (int row = 0; row < N_v2; row++)
	{
		for (int col = 0; col < M_v2; col++)
		{
			if (first[row][col] && second[row][col] == true)
			{
				cout << row << " " << col << endl;
			}
		}
	}

	return;

}
