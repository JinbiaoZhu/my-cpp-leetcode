#include "dfs.h"
#include<iostream>

using namespace std;

const int num_dir = 4;
const int num_coor = 2;
const int dir[num_dir][num_coor] = { 0,1,  // ��
                                     1,0,  // ��
                                     -1,0, // ��
                                     0,-1  // ��
};

// 1. ȷ�����ݺ�������������
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& isVisited, int x, int y)
{
    if (grid[x][y] == 0 || isVisited[x][y])  // ����������λ���ǵ���, �����Ѿ���������
    {
        return;
    }
    // �ǵ�����û�б�����
    isVisited[x][y] = true;  // ���������ó� "�Ѿ�����" ��״̬  

    for (int i = 0; i < num_dir; i++)  // �����������
    {
        int next_x = x + dir[i][0];  // ���� x ����
        int next_y = y + dir[i][1];  // ���� y ����

        if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size())  // �߽���
        {
            continue;
        }

        dfs(grid, isVisited, next_x, next_y);
    }

}

void main_dfs()
{
    // ��һ�а����������� N, M, ��ʾ���������������
    // ���� N ��, ÿ�а��� M ������, ����Ϊ 1 ���� 0
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

