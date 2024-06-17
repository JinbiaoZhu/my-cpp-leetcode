#include "four_sum_count.h"
#include<unordered_map>
#include <iostream>

using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
{
	unordered_map<int, int> tempAB;
	int count = 0;

	for (const int& i : nums1) 
	{
		for (const int& j : nums2) 
		{
			int temp_sum = i + j;
			if (tempAB.find(temp_sum) != tempAB.end()) 
			{
				tempAB[temp_sum]++;
				cout << "tempAB add " << temp_sum << "." << endl;
			}
			else 
			{
				tempAB.insert({ temp_sum, 1 });
				cout << "tempAB insert " << temp_sum << "." << endl;
			}
		}
	}

	for (const int& i : nums3)
	{
		for (const int& j : nums4)
		{
			int temp_sum = -1*(i + j);
			cout << "find key: " << temp_sum << endl;
			if (tempAB.find(temp_sum) != tempAB.end())
			{
				count += tempAB[temp_sum];
				cout << "found " << tempAB[temp_sum] << "/" << count << "." << endl;
			}
		}
	}
	return count;
}
