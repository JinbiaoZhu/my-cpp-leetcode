#include "canCompleteCircuit.h"

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    vector<int> rest;
	int current_sum = 0;
	int MAX_value = 2 << 20;
    
	for (int i = 0; i < gas.size(); i++)
	{
		rest.push_back(gas[i] - cost[i]);
	}

	// 1. 
	for (int i = 0; i < rest.size(); i++)
	{
		current_sum += rest[i];
		if (MAX_value >= current_sum)
		{
			MAX_value = current_sum;
		}
	}

	if (current_sum < 0)
	{
		return -1;
	}
	if (MAX_value >= 0)
	{
		return 0;
	}
	else
	{
		for (int i = rest.size() - 1; i > 0; i--)
		{
			MAX_value += rest[i];
			if (MAX_value >= 0)
			{
				return i;
			}
		}
	}
}
