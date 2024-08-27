#include "dfs.h"
#include <iostream>

using namespace std;

const int directions[4][2] = { 1,0,-1,0,0,1,0,-1 };
int N, M;


void dfs(vector<vector<int>>& grid, vector<vector<bool>>& isVisited, int x, int y)
{
	if (isVisited[x][y] == true)
	{
		return;
	}

	isVisited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int n_x = x + directions[i][0];
		int n_y = y + directions[i][1];

		if (n_x < 0 || n_x >= grid.size() || n_y < 0 || n_y >= grid[0].size())
		{
			continue;
		}

		if (grid[x][y] < grid[n_x][n_y])
		{
			continue;
		}

		dfs(grid, isVisited, n_x, n_y);
	}

	return;
}

bool isResult(vector<vector<int>>& grid, int x, int y) 
{
	vector<vector<bool>> isVisited(N, vector<bool>(M, false));

	dfs(grid, isVisited, x, y);

	bool isFirst = false, isSecond = false;

	for (int i = 0; i < M; i++)
	{
		if (isVisited[0][i] == true)
		{
			isFirst = true;
			break;
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (isVisited[i][0] == true)
		{
			isFirst = true;
			break;
		}
	}

	for (int j = 0; j < N; j++)
	{
		if (isVisited[j][M - 1] == true)
		{
			isSecond = true;
			break;
		}
	}

	for (int j = 0; j < M; j++)
	{
		if (isVisited[N-1][j] == true)
		{
			isSecond = true;
			break;
		}
	}

	if (isFirst == true && isSecond == true)
	{
		return true;
	}

	return false;
}

void main_dfs()
{
	cin >> N >> M;

	vector<vector<int>> grid(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> grid[i][j];
		}
	}
	cout << "----------" << endl;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	cout << "----------" << endl;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (isResult(grid, i ,j) == true)
			{
				cout << i << " " << j << endl;
			}
		}
	}

	return;
}
