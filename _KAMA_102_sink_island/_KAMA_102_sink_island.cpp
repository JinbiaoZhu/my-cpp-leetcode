// _KAMA_102_sink_island.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int directions[4][2] = {1,0,-1,0,0,1,0,-1};

void bfs(vector<vector<int>>& grid, int x, int y) 
{
	queue<pair<int,int>> myQueue;
	grid[x][y] = 2;
	myQueue.push(pair<int, int>{x, y});

	while (!myQueue.empty())
	{
		pair<int, int> cur = myQueue.front();
		myQueue.pop();

		int cur_x = cur.first, cur_y = cur.second;

		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + directions[i][0], next_y = cur_y + directions[i][1];

			if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size())
			{
				continue;
			}

			if (grid[next_x][next_y] == 1)
			{
				grid[next_x][next_y] = 2;
				myQueue.push(pair<int, int>{next_x, next_y});
			}
		}
	}
}

void bfs_main() 
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
	cout << "---------------------------" << endl;

	for (vector<int> row : grid)
	{
		for (int col : row)
		{
			cout << col << " ";
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;

	for (int row = 0; row < N; row++)
	{
		if (grid[row][0] == 1)
		{
			bfs(grid, row, 0);
		}
		if (grid[row][M - 1] == 1)
		{
			bfs(grid, row, M - 1);
		}
	}

	for (int col = 0; col < M; col++)
	{
		if (grid[0][col] == 1)
		{
			bfs(grid, 0, col);
		}
		if (grid[N - 1][col] == 1)
		{
			bfs(grid, N - 1, col);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (grid[i][j] > 0)
			{
				grid[i][j]--;
			}
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

	return;
}

void dfs(vector<vector<int>>& grid, int x, int y) 
{
	if (grid[x][y] == 0 || grid[x][y] == 2)
	{
		return;
	}

	grid[x][y] = 2;

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
}

void dfs_main() 
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
	cout << "---------------------------" << endl;

	for (vector<int> row : grid) 
	{
		for (int col : row) 
		{
			cout << col << " ";
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;

	for (int row = 0; row < N; row++)
	{
		if (grid[row][0] == 1)
		{
			dfs(grid, row, 0);
		}
		if (grid[row][M-1] == 1)
		{
			dfs(grid, row, M - 1);
		}
	}

	for (int col = 0; col < M; col++)
	{
		if (grid[0][col] == 1)
		{
			dfs(grid, 0, col);
		}
		if (grid[N - 1][col] == 1)
		{
			dfs(grid, N - 1, col);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (grid[i][j] > 0)
			{
				grid[i][j]--;
			}
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

    return;
}

int main()
{
    std::cout << "Hello World!\n";

	dfs_main();
	bfs_main();

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
