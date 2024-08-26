#include "adjacency_matrix.h"
#include<iostream>

using namespace std;

// 1. 确定回溯函数的输入参数表达式
void dfs_adj_matrix(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int>& path, int x, int n)
{
	// 2. 确定回溯函数终止条件
	//    x == n 说明回溯的节点重合, 然后就保存一条路径
	if (x == n)
	{
		result.push_back(path);
		return;
	}

	// 3. 遍历该节点的全部连接节点
	for (int i = 1; i <= n; i++)
	{
		if (graph[x][i] == 1)
		{
			path.push_back(i);
			dfs_adj_matrix(graph, result, path, i, n);
			path.pop_back();
		}
	}
}

void main_adj_matrix()
{
    // 两个整数 n, m, 表示图中拥有 n 个节点, m 条边
    // 后续 m 行，每行包含两个整数 s 和 t，表示图中的 s 节点与 t 节点中有一条路径
    int n, m, s, t;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        cin >> s >> t;
        graph[s][t] = 1;
    }

    for (vector<int>& row : graph)
    {
        for (int col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    vector<vector<int>> result;
    vector<int> path;

    path.push_back(1);

    dfs_adj_matrix(graph, result, path, 1, n);

    if (result.size() == 0)
    {
        cout << "None here" << endl;
        return;
    }
    else
    {
        for (vector<int>& i : result)
        {
            for (int j = 0; j < i.size() - 1; j++)
            {
                cout << i[j] << " ";
            }
            cout << i[i.size() - 1] << endl;
        }
    }

    cout << "===========" << endl;

    return;
}
