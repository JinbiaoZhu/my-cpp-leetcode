#include "bfs.h"
#include<queue>
#include<iostream>

using namespace std;

const int num_dir = 4;
const int num_coor = 2;
const int dir[num_dir][num_coor] = { 0,1,  // 右
									 1,0,  // 下
									 -1,0, // 左
									 0,-1  // 上
};

void bfs(vector<vector<int>>& grid, vector<vector<bool>>& isVisited, int x, int y)
{
	queue<pair<int, int>> que;
	que.push({ x, y });
	isVisited[x][y] = true;

	while (!que.empty())
	{
		pair<int, int> cur_coor = que.front();
		que.pop();

		int cur_x = cur_coor.first;
		int cur_y = cur_coor.second;
		
		for (int i = 0; i < num_dir; i++)
		{
			int next_x = cur_x + dir[i][0];
			int next_y = cur_y + dir[i][1];
			if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size())  // 边界检测
			{
				continue;
			}
			if (!isVisited[next_x][next_y] && grid[next_x][next_y] == 1)
			{
				que.push(pair<int, int>{next_x, next_y});
				isVisited[next_x][next_y] = true;
			}
		}
	}
}

void main_bfs()
{
    // 第一行包含两个整数 N, M, 表示矩阵的行数和列数
    // 后续 N 行, 每行包含 M 个数字, 数字为 1 或者 0
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

    for (vector<int> row : grid)
    {
        for (int col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    vector<vector<bool>> isVisited(N, vector<bool>(M, false));

    int result = 0;

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            if (!isVisited[x][y] && grid[x][y] == 1)
            {
                result++;
                bfs(grid, isVisited, x, y);
            }
        }
    }

    cout << result << endl;

    return;
}
