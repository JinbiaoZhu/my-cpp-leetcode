#include "combinationSum3.h"

vector<vector<int>> combinationSum3(int k, int n)
{
	vector<int> single_path;
	vector<vector<int>> total_result;
	int startIndex = 9;
	backtrack(single_path, total_result, k, n, startIndex);
	return total_result;
}

// ȷ�����ݺ������������
void backtrack(vector<int>& single_path, vector<vector<int>>& total_result, int k, int n, int startIndex) 
{
	// ȷ�����ݺ�������ֹ����
	if (single_path.size()==k)
	{
		if (vector_sum(single_path) == n)
		{
			total_result.push_back(single_path);
		}
		return;
	}

	// ȷ�����ݺ����ĵݹ��߼�
	for (startIndex; startIndex >= 1; startIndex--)
	{
		single_path.push_back(startIndex);
		backtrack(single_path, total_result, k, n, startIndex-1);
		single_path.pop_back();
	}
}

int vector_sum(vector<int> nums) 
{
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums.at(i);
	}
	return sum;
}