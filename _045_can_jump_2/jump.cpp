#include "jump.h"
#include<map>

using namespace std;

int jump(vector<int>& nums)
{
	if (nums.size()==1)
	{
		return 1;
	}

    int current_max_range = 0;
	int next_max_range = 0;
	int jumpt_steps = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		// 先第 i 个时间步的最大范围是什么
		next_max_range = max(next_max_range, i + nums[i]);
		// 如果 i 达到了当前的最大范围
		if (i==current_max_range)
		{
			jumpt_steps++;  // 就说明可以一步到位
			current_max_range = next_max_range;  // 更新下一个步数范围
			if (current_max_range>=nums.size()-1)
			{
				break;
			}
		}
	}
	return jumpt_steps;
}

/// <summary>
/// 这个 V2 函数只能在部分情况下成立
/// </summary>
/// <param name="nums"></param>
/// <returns></returns>
int jumpV2(vector<int>& nums)
{
	if (nums.size() == 1)
	{
		return 1;
	}

	map<int, int> stepTable;
	for (int i = 0; i < nums.size(); i++)
	{
		stepTable[i] = max(i, i + nums[i]);
	}

	//int current_max_range = 0;
	int jumpt_steps = 0;
	int previous_range = stepTable[0];

	for (int i = 0; i < nums.size(); i++)
	{
		// 先第 i 个时间步的最大范围是什么
		//current_max_range = stepTable[i];
		// 如果 i 达到了当前的最大范围
		if (i == previous_range)
		{
			jumpt_steps++;  // 就说明可以一步到位
			previous_range = stepTable[i];  // 更新下一个步数范围
			if (previous_range >= nums.size() - 1)
			{
				break;
			}
		}
	}
	return jumpt_steps;
}
