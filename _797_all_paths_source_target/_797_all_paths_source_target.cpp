// _797_all_paths_source_target.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int>& path, int n, int x) 
{
    if (x == n)
    {
        result.push_back(path);
        return;
    }

    for (int i : graph[x]) 
    {
        path.push_back(i);
        dfs(graph, result, path, n, i);
        path.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
{
    int N = graph.size();

    // 1. 创建邻接矩阵
    vector<vector<int>> matrix(N, vector<int>(N, 0));

    // 2. 初始化邻接矩阵
    for (int nodeIndex = 0; nodeIndex < N; nodeIndex++)
    {
        for (int lineIndex = 0; lineIndex < graph[nodeIndex].size(); lineIndex++)
        {
            matrix[nodeIndex][lineIndex] = 1;
        }
    }

    // 3. 初始化结果保存器
    vector<vector<int>> result;
    vector<int> path;
    path.push_back(0);

    // 4. 进行深度优先搜索
    dfs(graph, result, path, N-1, 0);

    // 5. 返回
    return result;
}

int main()
{
    std::cout << "Hello World!\n";

    int N;
    cin >> N;

    vector<int> sizes(N);
    for (int i = 0; i < N; i++)
    {
        cin >> sizes[i];
    }

    vector<vector<int>> graph;
    vector<int> node2line;
    for (int i = 0; i < N; i++)
    {
        node2line.clear();
        for (int j = 0; j < sizes[i]; j++)
        {
            int val;
            cin >> val;
            node2line.push_back(val);
        }
        graph.push_back(node2line);
    }

    vector<vector<int>> result = allPathsSourceTarget(graph);

    for (vector<int> i:result)
    {
        for (int j : i) 
        {
            cout << j << " ";
        }
        cout << endl;
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
