#include "partition.h"
#include<iostream>

using namespace std;

vector<vector<string>> partition(string s)
{
	vector<vector<string>> result;
	vector<string> single_result;
	int position = 0;
	backtrack(result, single_result, s, 0);
	return result;
}

// 确定回溯函数的输入输出
// position 等于 x , 就在 x 的右侧划分
void backtrack(vector<vector<string>>& result, vector<string>& single_result, const string& s, int position) 
{
	// 确定回溯函数的终止条件
	if (position>=s.size())
	{
		result.push_back(single_result);
		return;
	}

	// 确定回溯函数的回溯逻辑
	for (int i = position; i < s.size(); i++)
	{
		if (isPalindrome(s, position, i))
		{
			string substring = s.substr(position, i - position + 1);
			single_result.push_back(substring);
		}
		else
		{
			continue;
		}
		backtrack(result, single_result, s, i + 1);
		single_result.pop_back();
	}
}

bool isPalindrome(const string& s, int left, int right) 
{
	for (int i = left, j = right; i < j; i++, j--)
	{
		if (s[i] != s[j]) 
		{
			cout << s.substr(left, right - left + 1) << "-->false" << endl;
			return false;
		}
	}
	cout << s.substr(left, right - left + 1) << "-->true" << endl;
	return true;
}
