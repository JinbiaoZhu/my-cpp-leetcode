// _KAMA_094_product_transportation_v1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <queue>
#include <list>

#define infinity 9999

using namespace std;

struct linkNode
{
    int to;
    int val;
    linkNode(int to_, int val_) : to(to_), val(val_) {};
};

int main()
{
    std::cout << "Hello World!\n";

    // 第一行包含两个正整数，第一个正整数 n 表示该国一共有 n 个城市，第二个整数 m 表示这些城市中共有 m 条道路。 
    // 接下来为 m 行，每行包括三个整数，s、t 和 v，表示 s 号城市运输货物到达 t 号城市，道路权值为 v （单向图）。
    
    int n, m;
    cin >> n >> m;

    vector<list<linkNode>> graph(n + 1);
    vector<bool> isInQueue(n + 1, false);

    int s, t, v;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> t >> v;
        graph[s].push_back(linkNode(t, v));
    }

    int start = 1;
    int end = n;

    vector<int> minDist(n + 1, infinity);
    minDist[start] = 0;

    queue<int> myQueue;
    myQueue.push(start);

    while (!myQueue.empty())
    {
        int node = myQueue.front();
        myQueue.pop();

        isInQueue[node] = false;

        for (linkNode edge: graph[node])
        {
            int from = node;
            int to = edge.to;
            int val = edge.val;

            if (minDist[to] > minDist[from] + val)
            {
                minDist[to] = minDist[from] + val;
                if (isInQueue[to] == false)
                {
                    myQueue.push(to);
                    isInQueue[to] == true;
                }
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
