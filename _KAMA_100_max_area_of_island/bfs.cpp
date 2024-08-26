#include "bfs.h"
#include <queue>
#include <iostream>

using namespace std;

const int directions[4][2] = { 0,1,0,-1,1,0,-1,0 };
int COUNT_BFS;

void bfs(vector<vector<int>>& grid, vector<vector<bool>>& isVisited, int x, int y)
{
	queue<pair<int, int>> myQueue;
	myQueue.push(pair<int, int>{x, y});
	isVisited[x][y] = true;
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

			if (grid[next_x][next_y] == 1 && !isVisited[next_x][next_y])
			{
				myQueue.push(pair<int, int>{next_x, next_y});
				isVisited[next_x][next_y] = true;
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
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> grid[i][j];
		}
	}

	vector<vector<bool>> isVisited(N, vector<bool>(M, false));

	for (vector<int>& row : grid)
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
			if (!isVisited[i][j] && grid[i][j] == 1)
			{
				COUNT_BFS = 0;
				bfs(grid, isVisited, i, j);
				temp_result = max(COUNT_BFS, temp_result);
			}
		}
	}

	cout << temp_result << endl;

}
