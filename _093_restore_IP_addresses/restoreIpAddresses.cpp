#include"restoreIpAddresses.h"

using namespace std;

vector<string> restoreIpAddresses(string s) 
{
	vector<string> result;
	string path;
	int num_dot = 0;
	int startIndex = 0;
	if (s.size() < 4 || s.size() > 12) 
	{
		return result;
	}
	backtrack(result, path, s, num_dot, startIndex);
	return result;
}

	// 确定回溯函数的输入输出
	void backtrack(vector<string>& result, string& path, string& s, int num_dot, int startIndex) 
	{
		// 确定回溯函数的终止条件
		if (num_dot==3)
		{
			if (isValidNumber(s, startIndex, s.size()-1))
			{
				result.push_back(s);
			}
			return;
		}

		// 确定回溯函数的回溯逻辑
		for (int i = startIndex; i < s.size(); i++)
		{
			if (isValidNumber(s, startIndex, i)) 
			{
				s.insert(s.begin() + i + 1, '.');
				num_dot++;
				backtrack(result, path, s, num_dot, i + 1 + 1);
				num_dot--;
				s.erase(s.begin() + i + 1);
			}
			else
			{
				break;
			}
		}
	}

bool isValidNumber(string digit, int left, int right) 
{
	if (left>right)
	{
		return false;
	}
	if (digit[left] == '0' && left != right)
	{
		return false;
	}
	int num = 0;
	for (int i = left; i <= right; i++)
	{
		if (digit[i] > '9' && digit[i] < '0')
		{
			return false;
		}
		num = num * 10 + (digit[i] - '0');
		if (num > 255)
		{
			return false;
		}
	}
	return true;
}