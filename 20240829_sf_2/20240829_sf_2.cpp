// 20240829_sf_2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

void backtrace(vector<int>& nums, vector<bool>& isVisited, vector<vector<int>>& total_path, vector<int>& path) 
{
	// 记录是否结束回溯
	int count = 0;
	for (int i = 0; i < isVisited.size(); i++)
	{
		if (isVisited[i] == true)
		{
			count++;
		}
	}
	if (count == nums.size())
	{
		total_path.push_back(path);
		return;
	}

	// 回溯遍历
	for (int i = 0; i < nums.size(); i++)
	{
		if (isVisited[i] == false)
		{
			isVisited[i] == true;
			if (path.empty() == true)
			{
				path.push_back(nums[i]);
			}
			else 
			{
				int temp = path.front();
				if (temp % nums[i] != 0 || nums[i] % temp != 0)
				{
					continue;
				}
			}
			backtrace(nums, isVisited, total_path, path);
			path.pop_back();
			isVisited[i] = false;
		}
		else
		{
			continue;
		}
	}
}






int main()
{
	cout << 0 << endl;


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
