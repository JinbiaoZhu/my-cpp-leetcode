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
		// �ȵ� i ��ʱ�䲽�����Χ��ʲô
		next_max_range = max(next_max_range, i + nums[i]);
		// ��� i �ﵽ�˵�ǰ�����Χ
		if (i==current_max_range)
		{
			jumpt_steps++;  // ��˵������һ����λ
			current_max_range = next_max_range;  // ������һ��������Χ
			if (current_max_range>=nums.size()-1)
			{
				break;
			}
		}
	}
	return jumpt_steps;
}

/// <summary>
/// ��� V2 ����ֻ���ڲ�������³���
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
		// �ȵ� i ��ʱ�䲽�����Χ��ʲô
		//current_max_range = stepTable[i];
		// ��� i �ﵽ�˵�ǰ�����Χ
		if (i == previous_range)
		{
			jumpt_steps++;  // ��˵������һ����λ
			previous_range = stepTable[i];  // ������һ��������Χ
			if (previous_range >= nums.size() - 1)
			{
				break;
			}
		}
	}
	return jumpt_steps;
}
