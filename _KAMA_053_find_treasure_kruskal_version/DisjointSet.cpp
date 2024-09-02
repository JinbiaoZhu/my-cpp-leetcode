#include "DisjointSet.h"


void init(vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		nums[i] = i;
	}
	return;
}

int find(vector<int>& nums, int val)
{
	if (val = nums[val])
	{
		return val;
	}

	nums[val] = find(nums, nums[val]);
	return nums[val];
}

void join(vector<int>& nums, int a, int b)
{
	a = find(nums, a);
	b = find(nums, b);

	if (a == b)
	{
		return;
	}

	nums[b] = a;
	return;
}


