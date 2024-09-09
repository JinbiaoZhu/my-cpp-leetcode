// _KAMA_097_visit_park.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <list>
#include <climits>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    //  第一行包含两个整数 N, M, 分别表示景点的数量和道路的数量。 
    int N, M;
    cin >> N >> M;

    //  接下来的 M 行，每行包含三个整数 u, v, w，表示景点 u 和景点 v 之间有一条长度为 w 的双向道路。
    int u, v, w;
    //  vector<vector<vector<int>>> grid(N + 1, vector<vector<int>>(N + 1, vector<int>(N + 1, 10005)));
    vector<vector<int>> gridV2(N + 1, vector<int>(N + 1, 10005));
    //for (int i = 0; i < M; i++)
    //{
    //    cin >> u >> v >> w;
    //    grid[u][v][0] = w;
    //    grid[v][u][0] = w;
    //}
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        gridV2[u][v] = w;
        gridV2[v][u] = w;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                gridV2[i][j] = min(gridV2[i][k] + gridV2[k][j], gridV2[i][j]);
            }
        }
    }

    int z, start, end;
    cin >> z;

    for (int i = 0; i < z; i++)
    {
        cin >> start >> end;
        if (gridV2[start][end] == 10005)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << gridV2[start][end] << endl;
        }
    }

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
