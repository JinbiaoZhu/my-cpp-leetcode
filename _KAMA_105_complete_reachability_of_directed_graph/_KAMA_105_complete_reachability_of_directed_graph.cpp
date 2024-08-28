// _KAMA_105_complete_reachability_of_directed_graph.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;


void dfs(vector<list<int>>& graph, vector<bool>& isVisited, int key) 
{
    if (isVisited[key] == true)
    {
        return;
    }

    isVisited[key] = true;

    list<int> keys = graph[key];
    for ( int i: keys)
    {
        dfs(graph, isVisited, i);
    }
}


int main()
{
    std::cout << "Hello World!\n";

    // 输入描述: 
    // 第一行包含两个正整数，表示节点数量 N 和边的数量 K。
    // 后续 K 行，每行两个正整数 s 和 t，表示从 s 节点有一条边单向连接到 t 节点。
    int N, K;
    cin >> N >> K;

    // 这里从 1 开始, 因此这里就 N + 1 方便索引
    vector<list<int>> graph(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int s, t;
        cin >> s >> t;

        graph[s].push_back(t);
    }

    vector<bool> isVisited(N + 1, false);

    dfs(graph, isVisited, 1);

    for (int i = 1; i <= N; i++)
    {
        if (isVisited[i] == false)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << 1 << endl;

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
