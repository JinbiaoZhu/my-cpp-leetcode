#include "dfs.h"
#include<iostream>

using namespace std;

const int num_dir = 4;
const int num_coor = 2;
const int dir[num_dir][num_coor] = { 0,1,  // 右
                                     1,0,  // 下
                                     -1,0, // 左
                                     0,-1  // 上
};

// 1. 确定回溯函数的输入和输出
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& isVisited, int x, int y)
{
    if (grid[x][y] == 0 || isVisited[x][y])  // 当遍历到的位置是岛屿, 或者已经遍历过了
    {
        return;
    }
    // 是岛屿且没有被遍历
    isVisited[x][y] = true;  // 在这块地设置成 "已经遍历" 的状态  

    for (int i = 0; i < num_dir; i++)  // 广度优先搜索
    {
        int next_x = x + dir[i][0];  // 更新 x 坐标
        int next_y = y + dir[i][1];  // 更新 y 坐标

        if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size())  // 边界检测
        {
            continue;
        }

        dfs(grid, isVisited, next_x, next_y);
    }

}

void main_dfs()
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
                dfs(grid, isVisited, x, y);
            }
        }
    }

    cout << result << endl;

    return;
}

