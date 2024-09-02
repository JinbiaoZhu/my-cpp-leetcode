// _KAMA_047_join_science_conference.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#define infinity 9999

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    // 第一行包含两个正整数，第一个正整数 N 表示一共有 N 个公共汽车站，第二个正整数 M 表示有 M 条公路。
    // 接下来为 M 行，每行包括三个整数，S、E 和 V，代表了从 S 车站可以单向直达 E 车站，并且需要花费 V 单位的时间。
    // //////////////////////////////////////////////////////////////////
    // 这一段代码都是在构建图的邻接矩阵
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1, vector<int>(N + 1, infinity));

    int S, E, V;
    for (int i = 0; i < M; i++)
    {
        cin >> S >> E >> V;
        graph[S][E] = V;
    }
    // //////////////////////////////////////////////////////////////////

    int start = 1;
    int end = N;

    vector<int> minDist(N + 1, infinity);
    vector<bool> isVisitied(N + 1, false);

    minDist[start] = 0;
    
    for (int i = 1; i <= N; i++)
    {
        int minVal = infinity;
        int curPos = 1;

        for (int v = 1; v <= N; v++)
        {
            // 如果没遍历过 且 该点到源节点的最短路径打破纪录
            if (isVisitied[v] == false && minDist[v] < minVal)
            {
                minVal = minDist[v];
                curPos = v;
            }
        } // 经过遍历后, 找到了距离源节点的最短的位置和距离

        isVisitied[curPos] = true;  // 把这个位置标记成已经遍历过的

        for (int j = 1; j <= N; j++)
        {
            // 更新非访问节点到源点的距离 (即更新 minDist 数组)
            if (isVisitied[j] == false && graph[curPos][j] != infinity && minDist[curPos] + graph[curPos][j] < minDist[j])
            {
                minDist[j] = graph[curPos][j] + minDist[curPos];
            }
        }
    }

    if (minDist[end] == infinity)
    {
        cout << -1 << endl;
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
