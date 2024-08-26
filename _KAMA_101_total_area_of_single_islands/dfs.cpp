#include "dfs.h"
#include <iostream>

using namespace std;

int COUNT_DFS;
const int directions[4][2] = { 0,1,0,-1,1,0,-1,0 };

void dfs(vector<vector<int>>& grid, int x, int y)
{
	if (grid[x][y] == 0)
	{
		return;
	}

	grid[x][y] = 0;

	COUNT_DFS++;

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + directions[i][0];
		int next_y = y + directions[i][1];

		if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size())
		{
			continue;
		}

		dfs(grid, next_x, next_y);
	}
	return;
}

void main_dfs()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> grid(N, vector<int>(M, 0));
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < M; col++)
		{
			cin >> grid[row][col];
		}
	}

	for (vector<int>& row : grid) 
	{
		for (int col:row )
		{
			cout << col << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < N; i++)
	{
		if (grid[i][0] == 1)
		{
			dfs(grid, i, 0);
		}
		if (grid[i][M - 1] == 1)
		{
			dfs(grid, i, M - 1);
		}
	}
	for (int j = 0; j < M; j++)
	{
		if (grid[0][j] == 1)
		{
			dfs(grid, 0, j);
		}
		if (grid[N-1][j] == 1)
		{
			dfs(grid, N - 1, j);
		}
	}

	COUNT_DFS = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (grid[i][j] == 1)
			{
				dfs(grid, i, j);
			}
		}
	}

	cout << COUNT_DFS << endl;
}
