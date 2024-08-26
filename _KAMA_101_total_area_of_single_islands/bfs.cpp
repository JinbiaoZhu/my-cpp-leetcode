#include "bfs.h"
#include <queue>
#include <iostream>

using namespace std;

int COUNT_BFS;
const int directions[4][2] = { 0,1,0,-1,1,0,-1,0 };


void bfs(vector<vector<int>>& grid, int x, int y)
{
	queue<pair<int, int>> myQueue;

	myQueue.push(pair<int, int>{x, y});
	grid[x][y] = 0;

	COUNT_BFS++;

	while (!myQueue.empty())
	{
		pair<int, int> current = myQueue.front();
		myQueue.pop();

		int current_x = current.first;
		int current_y = current.second;

		for (int i = 0; i < 4; i++)
		{
			int next_x = current_x + directions[i][0];
			int next_y = current_y + directions[i][1];

			if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size())
			{
				continue;
			}

			if (grid[next_x][next_y] == 1)
			{
				myQueue.push(pair<int, int>{next_x, next_y});
				grid[next_x][next_y] = 0;
				COUNT_BFS++;
			}
		}
	}
}

void main_bfs()
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
		for (int col : row)
		{
			cout << col << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < N; i++)
	{
		if (grid[i][0] == 1)
		{
			bfs(grid, i, 0);
		}
		if (grid[i][M - 1] == 1)
		{
			bfs(grid, i, M - 1);
		}
	}
	for (int j = 0; j < M; j++)
	{
		if (grid[0][j] == 1)
		{
			bfs(grid, 0, j);
		}
		if (grid[N - 1][j] == 1)
		{
			bfs(grid, N - 1, j);
		}
	}

	COUNT_BFS = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (grid[i][j] == 1)
			{
				bfs(grid, i, j);
			}
		}
	}

	cout << COUNT_BFS << endl;
}
