#include "dfs.h"
#include <iostream>

using namespace std;

const int directions[4][2] = { 0,1,0,-1,1,0,-1,0 };
int COUNT_DFS = 0;

void dfs(vector<vector<int>>& grid, vector<vector<bool>>& isVisited, int x, int y)
{
	if (grid[x][y] == 0 || isVisited[x][y] == true)
	{
		return;
	}
	
	isVisited[x][y] = true;
	COUNT_DFS++;

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + directions[i][0];
		int next_y = y + directions[i][1];

		if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size())
		{
			continue;
		}

		dfs(grid, isVisited, next_x, next_y);
	}
}

void main_dfs()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> grid(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> grid[i][j];
		}
	}

	vector<vector<bool>> isVisited(N, vector<bool>(M, false));

	for (vector<int>& row:grid) 
	{
		for (int col : row)
		{
			cout << col << " ";
		}
		cout << endl;
	}

	int temp_result = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			COUNT_DFS = 0;
			dfs(grid, isVisited, i, j);
			temp_result = max(COUNT_DFS, temp_result);
		}
	}

	cout << temp_result << endl;
}
