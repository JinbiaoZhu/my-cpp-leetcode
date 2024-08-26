#include "adjacency_matrix.h"
#include<iostream>

using namespace std;

// 1. ȷ�����ݺ���������������ʽ
void dfs_adj_matrix(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int>& path, int x, int n)
{
	// 2. ȷ�����ݺ�����ֹ����
	//    x == n ˵�����ݵĽڵ��غ�, Ȼ��ͱ���һ��·��
	if (x == n)
	{
		result.push_back(path);
		return;
	}

	// 3. �����ýڵ��ȫ�����ӽڵ�
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
    // �������� n, m, ��ʾͼ��ӵ�� n ���ڵ�, m ����
    // ���� m �У�ÿ�а����������� s �� t����ʾͼ�е� s �ڵ��� t �ڵ�����һ��·��
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
