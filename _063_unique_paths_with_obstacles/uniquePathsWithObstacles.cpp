#include "uniquePathsWithObstacles.h"

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    // 1. 确定动态规划数组和下标
    //    DP[i][j] 表示从 (0,0) 点到 (i,j) 点可行的路径数量
    //    机器人只能向右走和向下走！
    int R = obstacleGrid.size(), C = obstacleGrid[0].size();
    vector<vector<int>> DP(R, vector<int>(C, 0));
    
    // 3. 确定动态规划的初始化
    //    DP[0][0] = 0; DP[i][0] = 1; DP[0][j] = 1; 
    //    如果 i 和 j 的边边上有障碍物的话, 就到障碍物为止
    //    因为机器人只能向右走和向下走, 因此不存在 "绕过去" 的可能
    DP[0][0] = 0;
    for (int row = 1; row < R; row++)
    {
        if (obstacleGrid[row][0] == 1)
        {
            break;
        }
        DP[row][0] = 1;
    }
    for (int col = 1; col < C; col++)
    {
        if (obstacleGrid[0][col] == 1)
        {
            break;
        }
        DP[0][col] = 1;
    }
    
    if (obstacleGrid[0][0]==1 || obstacleGrid[R-1][C-1]==1)
    {
        return 0;
    }

    // 2. 确定动态规划数组的递推关系
    //    DP[i][j] = DP[i-1][j] + DP[i][j-1]
    // 4. 确定动态规划的遍历
    //    从左向右, 从上向下
    for (int row = 1; row < R; row++)
    {
        for (int col = 1; col < C; col++)
        {
            if (obstacleGrid[row][col] == 1)
            {
                continue;
            }
            DP[row][col] = DP[row - 1][col] + DP[row][col - 1];
        }
    }

    // 5. 人工推演
    //    省略

    return DP[R - 1][C - 1];
}
