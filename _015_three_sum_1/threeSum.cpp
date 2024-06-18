#include "threeSum.h"
#include<unordered_map>
#include<algorithm>
#include<iostream>

using namespace std;

vector<vector<int>> threeSum_solution1(vector<int>& nums)
{
	unordered_map<int, pair<int,int>> temp;
	vector<vector<int>> result;
	unordered_map<int, int> indexSet;
	unordered_map<int, int> valueSet;

	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i+1; j < nums.size(); j++) 
		{
			int temp_sum = nums[i] + nums[j];
			temp.insert({ temp_sum ,{i,j} });
			cout << temp_sum << " " << i << " " << j << " " << endl;
		}
	}

	for (int k = 0; k < nums.size(); k++) 
	{
		int match_value = -1 * nums[k];
		cout << "match value: " << match_value << "." << endl;

		if (temp.find(match_value) != temp.end()) 
		{
			cout << "Jump first." << endl;
			pair<int, int> indexes = temp[match_value];
			cout << "pair<int,int> indexes is: [" << indexes.first << ", " << indexes.second << "]" << endl;
			if (indexes.first!=k && indexes.second!=k && indexes.first!=indexes.second)
			{
				cout << "Jump second." << endl;
				if (indexSet.find(indexes.first) != indexSet.end() &&
					indexSet.find(indexes.second) != indexSet.end() &&
					indexSet.find(k) != indexSet.end())
				{
					cout << "Jump third-if." << endl;
					continue;
				}
				else 
				{
					cout << "Jump third-else." << endl;
					if (valueSet.find(nums[indexes.first])!=valueSet.end()&&
						valueSet.find(nums[indexes.second]) != valueSet.end() &&
						valueSet.find(nums[k]) != valueSet.end())
					{
						cout << "Jump 4th-if." << endl;
						continue;
					}
					else 
					{
						cout << "Jump 4th-else." << endl;
						vector<int> a_vector = { nums[indexes.first] , nums[indexes.second] , nums[k] };
						result.push_back(a_vector);
						indexSet.insert({ indexes.first ,1 });
						indexSet.insert({ indexes.second ,1 });
						indexSet.insert({ k ,1 });
						valueSet.insert({ nums[indexes.first] ,1 });
						valueSet.insert({ nums[indexes.second] ,1 });
						valueSet.insert({ nums[k] ,1 });
					}
				}
			}
		}

	}
	return result;
}

vector<vector<int>> threeSum_solution2(vector<int>& nums) 
{
	vector<vector<int>> result;
	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] > 0) 
		{
			return result;
		}

		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}

		int left = i + 1;
		int right = nums.size() - 1;

		while (left<right)
		{
			if (nums[i] + nums[left] + nums[right] > 0) 
			{
				right--;
			}
			else if (nums[i] + nums[left] + nums[right] < 0) 
			{
				left++;
			}
			else 
			{
				result.push_back(vector<int>{ nums[i] , nums[left] , nums[right] });
				while (left < right && nums[left] == nums[left + 1]) { left++; }
				while (left < right && nums[right] == nums[right - 1]) { right--; }

				right--;
				left++;
			}


		}
	}

	return result;
}
