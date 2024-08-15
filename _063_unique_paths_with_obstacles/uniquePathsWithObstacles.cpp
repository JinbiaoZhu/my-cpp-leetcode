#include "uniquePathsWithObstacles.h"

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    // 1. ȷ����̬�滮������±�
    //    DP[i][j] ��ʾ�� (0,0) �㵽 (i,j) ����е�·������
    //    ������ֻ�������ߺ������ߣ�
    int R = obstacleGrid.size(), C = obstacleGrid[0].size();
    vector<vector<int>> DP(R, vector<int>(C, 0));
    
    // 3. ȷ����̬�滮�ĳ�ʼ��
    //    DP[0][0] = 0; DP[i][0] = 1; DP[0][j] = 1; 
    //    ��� i �� j �ı߱������ϰ���Ļ�, �͵��ϰ���Ϊֹ
    //    ��Ϊ������ֻ�������ߺ�������, ��˲����� "�ƹ�ȥ" �Ŀ���
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

    // 2. ȷ����̬�滮����ĵ��ƹ�ϵ
    //    DP[i][j] = DP[i-1][j] + DP[i][j-1]
    // 4. ȷ����̬�滮�ı���
    //    ��������, ��������
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

    // 5. �˹�����
    //    ʡ��

    return DP[R - 1][C - 1];
}
