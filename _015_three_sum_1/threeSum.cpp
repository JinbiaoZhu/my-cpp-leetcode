#include "threeSum.h"
#include<unordered_map>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum_solution1(vector<int>& nums)
{
	unordered_map<int, pair<int,int>> temp;
	vector<vector<int>> result;
	unordered_map<int, int> indexSet;

	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i; j < nums.size(); j++) 
		{
			int temp_sum = nums[i] + nums[j];
			temp.insert({ temp_sum ,{i,j} });
		}
	}

	for (int k = 0; k < nums.size(); k++) 
	{
		int match_value = -1 * nums[k];

		if (temp.find(match_value) != temp.end()) 
		{
			pair<int, int> indexes = temp[match_value];
			if (indexes.first!=k && indexes.second!=k && indexes.first!=indexes.second)
			{
				if (indexSet.find(indexes.first) == indexSet.end() &&
					indexSet.find(indexes.second) == indexSet.end() &&
					indexSet.find(k) == indexSet.end()) 
				{
					vector<int> a_vector = { nums[indexes.first] , nums[indexes.second] , nums[k]};
					result.push_back(a_vector);
					indexSet.insert({ indexes.first ,1 });
					indexSet.insert({ indexes.second ,1});
					indexSet.insert({ k ,1 });
				}
			}
		}

	}

	return result;
}
