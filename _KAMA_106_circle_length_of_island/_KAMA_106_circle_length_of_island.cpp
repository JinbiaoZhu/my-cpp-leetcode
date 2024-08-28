// _KAMA_106_circle_length_of_island.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int directions[4][2] = { 1,0,-1,0,0,1,0,-1 };
int result = 0;

int main()
{
    std::cout << "Hello World!\n";

    // 输入描述;
    // 第一行包含两个整数 N, M，表示矩阵的行数和列数。
    // 之后 N 行，每行包含 M 个数字，数字为 1 或者 0，表示岛屿的单元格。
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < M; col++)
        {
            cin >> grid[row][col];
        }
    }
    cout << "==========" << endl;

    for ( vector<int> & row : grid )
    {
        for (int col: row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << "==========" << endl;

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < M; col++)
        {
            if (grid[row][col] == 1)
            {
                for (int i = 0; i < 4; i++)
                {
                    int x = row + directions[i][0];
                    int y = col + directions[i][1];

                    if (x < 0 || x >= N || y < 0 || y >= M || grid[x][y] == 0)
                    {
                        result++;
                    }
                }
            }
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
