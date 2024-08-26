#include "adjacency_table.h"
#include<iostream>

using namespace std;

void dfs_adj_table(vector<list<int>>& graph, vector<vector<int>>& result, vector<int>& path, int x, int n)
{
	if (x == n)
	{
		result.push_back(path);
	}

	for (int i : graph.at(x))
	{
		path.push_back(i);
		dfs_adj_table(graph, result, path, i, n);
		path.pop_back();
	}
}

void main_adj_table()
{
	// �������� n, m, ��ʾͼ��ӵ�� n ���ڵ�, m ����
	// ���� m �У�ÿ�а����������� s �� t����ʾͼ�е� s �ڵ��� t �ڵ�����һ��·��
	int n, m, s, t;
	cin >> n >> m;

	vector<list<int>> graph(m+1);
	for (int i = 1; i <= m; i++)
	{
		cin >> s >> t;
		graph[s].push_back(t);
	}

	for (int i = 1; i < graph.size(); i++)
	{
		for (int j : graph[i])
		{
			cout << j << " ";
		}
		cout << endl;
	}

	vector<vector<int>> result;
	vector<int> path;

	path.push_back(1);

	dfs_adj_table(graph, result, path, 1, n);

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
