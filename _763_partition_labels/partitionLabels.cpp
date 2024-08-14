#include "partitionLabels.h"
#include<iostream>

using namespace std;

vector<int> partitionLabels(string& s)
{
	vector<int> result;

    // 1. 统计每个字母的最后出现位置
	vector<int> times(26, 0);
	for (int i = 0; i < s.size(); i++)
	{
		times[s[i] - 'a'] = i;
	}

	for (int i = 0; i < times.size(); i++)
	{
		cout << times[i] << " ";
	}
	cout << endl;

	// 2. 
	int left = 0, right = 0;
	int current_max = times[s[0] - 'a'];
	for (int i = 0; i < s.size(); i++)
	{
		current_max = times[s[i] - 'a'];
		right = max(current_max, right);
		if (right == i)
		{
			result.push_back(right - left + 1);
			left = i + 1;
		}
	}
	return result;
}
