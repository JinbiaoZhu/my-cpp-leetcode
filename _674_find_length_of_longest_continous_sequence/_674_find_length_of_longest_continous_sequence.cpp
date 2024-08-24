// _674_find_length_of_longest_continous_sequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int findLengthOfLCIS_myself(vector<int>& nums) 
{
	///  我自己写的题解, 通过率至多 20/35 = 57
    vector<int> differences(nums.size(), 0);
	differences[0] = nums[0];

	for (int i = 1; i < differences.size(); i++)
	{
		differences[i] = nums[i] - nums[i - 1];
	}

	int result = 0;
	int max_result = 0;
	for (int i = 0; i < differences.size(); i++)
	{
		if (differences[i] > 0)
		{
			result += 1;
		}
		else
		{
			result = 0;
		}
		if (result > max_result)
		{
			max_result = result;
		}
	}

	return max_result;
}

int findLengthOfLCIS(vector<int>& nums) 
{
	// 1. dp[i] 表示以 nums[i] 结尾的最长连续递增子序列的长度
	// 3. dp[i] 初始化全为 1
	vector<int> dp(nums.size(), 1);

	// 4. dp[i] 从左向右从前向后遍历
	for (int i = 1; i < dp.size(); i++)
	{
		// 2. if (nums[i] > nums[i-1]) {dp[i] = dp[i-1]+1;}
		if (nums[i] > nums[i-1])
		{
			dp[i] = dp[i - 1] + 1;
		}
	}

	int current_max = dp[0];
	for (int i = 1; i < dp.size(); i++)
	{
		if (dp[i] > current_max)
		{
			current_max = dp[i];
		}
	}

	// 5. 人工数值模拟
	for (int i: dp)
	{
		cout << i << " ";
	}

	return current_max;
}

int main()
{
    std::cout << "Hello World!\n";

	int numsLength;
	cin >> numsLength;

	vector<int> nums(numsLength, 0);
	for (int i = 0; i < numsLength; i++)
	{
		cin >> nums[i];
	}

	// int result = findLengthOfLCIS_myself(nums);
	int result = findLengthOfLCIS(nums);

	cout << result << endl;

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
