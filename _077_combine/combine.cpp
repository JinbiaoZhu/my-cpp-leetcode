#include"combine.h"

vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> total_result;
	vector<int> path;
	int startIndex = 1;

	backtracking(n, k, startIndex, total_result, path);

	return total_result;
}

// ȷ�����ݺ������������
void backtracking(int n, int k, int startIndex, vector<vector<int>>& total_result, vector<int>& path)
{
	// ȷ�����ݺ�������ֹ����
	if (path.size()==k)
	{
		total_result.push_back(path);
		return;
	}

	// ȷ�������߼�
	for (int i = startIndex; i <= n - (k-path.size())+1; i++)
	{
		path.push_back(i);
		backtracking(n, k, i + 1, total_result, path);
		path.pop_back();
	}
}




