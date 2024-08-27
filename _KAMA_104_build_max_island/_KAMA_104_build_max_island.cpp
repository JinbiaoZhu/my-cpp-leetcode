// _KAMA_104_build_max_island.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int COUNT = 0;
int N, M;
int directions[4][2] = { 1,0,-1,0,0,1,0,-1 };

// 1. 确定递归函数的输入参数
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& isVisited, int x, int y, int mark) 
{
	// 2. 确定回溯函数的终止条件
	//    本题目就是 "该区域被访问过" 或者 "该区域是海水" 的时候, 停止这个方向的遍历
	if (isVisited[x][y] == true || grid[x][y] == 0)
	{
		return;
	}

	// 3. 确定本层递归逻辑
	//    接下来处理的状态是 "没有被访问过" 且 "该区域是陆地"
	grid[x][y] = mark;
	isVisited[x][y] = true;
	COUNT++;

	// 4. 按照方向进入下一个递归
	for (int i = 0; i < 4; i++)
	{
		int nx = x + directions[i][0];
		int ny = y + directions[i][1];

		if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size())
		{
			continue;
		}

		dfs(grid, isVisited, nx, ny, mark);
	}
}


int main()
{
    std::cout << "Hello World!\n";

	cin >> N >> M;
	vector<vector<int>> grid(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> grid[i][j];
		}
	}

	// 打印输出
	for ( vector<int>& row:grid )
	{
		for (int col:row)
		{
			cout << col << " ";
		}
		cout << endl;
	}
	cout << "----------" << endl;

	vector<vector<bool>> isVisited(N, vector<bool>(M, false));
	unordered_map<int, int> gridNum;

	int mark = 2;
	bool isAllGrid = true;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0;  j < M;  j++)
		{
			// 如果出现了海水, 说明不是全是陆地, 那么不能用乘积的计算方式
			if (grid[i][j] == 0)
			{
				isAllGrid = false;
			}

			if (isVisited[i][j] == false && grid[i][j] == 1)
			{
				COUNT = 0;
				dfs(grid, isVisited, i, j, mark);
				gridNum[mark] = COUNT;
				mark++;
			}
		}
	}

	if (isAllGrid == true)
	{
		cout << N * M << endl;
		return 0;
	}

	int result = 0;

	unordered_set<int> visitedGrid;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			COUNT = 1;
			visitedGrid.clear();
			if (grid[i][j] == 0)
			{
				for (int d = 0; d < 4; d++)
				{
					int ni = i + directions[d][0];
					int nj = j + directions[d][1];

					if (ni < 0 || ni >= grid.size() || nj < 0 || nj >= grid[0].size())
					{
						continue;
					}
					if (visitedGrid.count(grid[ni][nj]))
					{
						continue;
					}
					COUNT += gridNum[grid[ni][nj]];
					visitedGrid.insert(grid[ni][nj]);
				}
			}

			result = max(COUNT, result);
		}
	}
	cout << result << endl;

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
