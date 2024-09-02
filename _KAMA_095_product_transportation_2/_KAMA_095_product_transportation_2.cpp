// _KAMA_095_product_transportation_2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <queue>

#define infinity 9999

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    // 第一行包含两个正整数，第一个正整数 n 表示该国一共有 n 个城市，第二个整数 m 表示这些城市中共有 m 条道路。
    // 接下来为 m 行，每行包括三个整数，s、t 和 v，表示 s 号城市运输货物到达 t 号城市，道路权值为 v。
    int n, m;
    cin >> n >> m;

    int s, t, v;
    vector<vector<int>> graph;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> t >> v;
        graph.push_back(vector<int>{ s, t, v });
    }

    int start = 1;
    int end = n;

    vector<int> minDist(n + 1, infinity);
    minDist[start] = 0;

    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        for ( vector<int>& edge: graph )
        {
            int from = edge[0];
            int to = edge[1];
            int val = edge[2];

            if (i < n)
            {
                if (minDist[from] != infinity && minDist[to] > minDist[from] + val)
                {
                    minDist[to] = minDist[from] + val;
                }
            }
            else 
            {
                if (minDist[from] != infinity && minDist[to] > minDist[from] + val)
                {
                    flag = true;
                }
            }
        }
    }

    if (flag == true)
    {
        cout << "circle" << endl;
    }
    else if (minDist[end] == infinity)
    {
        cout << "unconnected" << endl;
    }
    else
    {
        cout << minDist[end] << endl;
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
