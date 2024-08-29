// _KAMA_053_find_treasure.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int V, E;    // 声明节点 V 和边 E
int result;    // 声明结果数值
vector<vector<int>> grid;    // 声明连接图和每天边的权值
vector<int> minDist;    // 声明每个节点距离最小生成树最短的值
vector<bool> isTree;    // 声明每个节点是否在最小生成树里


int main()
{
    std::cout << "Hello World!\n";

    // 输入描述:
    // 第一行包含两个整数 V 和 E，V 代表顶点数，E 代表边数。顶点编号是从 1 到 V 。
    // 例如：V = 2 ，一个有两个顶点，分别是 1 和 2 。
    // 接下来共有 E 行，每行三个整数 v1，v2 和 val，v1 和 v2 为边的起点和终点，val代表边的权值。

    cin >> V >> E;

    result = 0;
    grid = vector<vector<int>>(V + 1, vector<int>(V + 1, 10001));

    for (int e = 0; e < E; e++)
    {
        int v1, v2, val;
        cin >> v1 >> v2 >> val;

        grid[v1][v2] = val;
        grid[v2][v1] = val;
    }

    minDist = vector<int>(V + 1, 10001);
    isTree = vector<bool>(V + 1, false);

    for (int i = 1; i < V; i++)
    {
        // 1. 选择距离生成树最近的最小节点
        int cur = -1;
        int minVal = 100000000;
        for (int j = 1; j <= V; j++)
        {
            // 选择条件: 当前节点没有在树里面, 且当前节点距离最小生成树的最小距离打破纪录
            if (isTree[j] == false && minDist[j] < minVal)
            {
                minVal = minDist[j];
                cur = j;
            }
        }

        // 2. 将距离最小的节点加入到最小生成树
        isTree[cur] = true;

        // 3. 更新非生成树节点到生成树的最小距离
        for (int j = 1; j <= V; j++)
        {
            // 更新条件:
            // (a). 这个节点不在树中;
            // (b). 这个节点到 cur 的距离, 比这个节点到最小生成树的距离要小;
            if (isTree[j] == false && grid[cur][j] < minDist[j])
            {
                minDist[j] = grid[cur][j];
            }
        }
    }

    // 4. 作答, 求出权值
    for (int i = 2; i <= V; i++)
    {
        result += minDist[i];
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
