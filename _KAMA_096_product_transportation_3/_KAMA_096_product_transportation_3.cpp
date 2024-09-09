// _KAMA_096_product_transportation_3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<list>
#include<vector>
#include<climits>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    // 第一行包含两个正整数，第一个正整数 n 表示该国一共有 n 个城市，第二个整数 m 表示这些城市中共有 m 条道路。
    int n, m;
    // 接下来为 m 行，每行包括三个整数，s、t 和 v，表示 s 号城市运输货物到达 t 号城市，道路权值为 v。
    int s, t, v;
    // 最后一行包含三个正整数，src、dst、和 k，src 和 dst 为城市编号，从 src 到 dst 经过的城市数量限制。
    int src, dst, k;

    cin >> n >> m;
    
    vector<vector<int>> graph(m);

    for (int i = 0; i < m; i++)
    {
        cin >> s >> t >> v;

        graph[i] = vector<int>{ s, t, v };
    }

    cin >> src >> dst >> k;

    vector<int> minDist(n + 1, INT_MAX);
    vector<int> minDistCopy(n + 1);

    minDist[src] = 0;

    for (int i = 1; i <= k+1; i++)
    {
        minDistCopy = minDist;

        for (vector<int>& edge: graph )
        {

            int from = edge[0];
            int to = edge[1];
            int value = edge[2];

            if (minDistCopy[from] != INT_MAX && minDist[to] > minDistCopy[from] + value)
            {
                minDist[to] = minDistCopy[from] + value;
            }
        }
    }

    if (minDist[dst] == INT_MAX)
    {
        cout << "unreachable" << endl;
    }
    else
    {
        cout << minDist[dst] << endl;
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
