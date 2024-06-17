#include "two_sum.h"
#include<unordered_map>
#include<algorithm>
#include<iostream>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> tmp;
    vector<int> result;

    for (int i=0;i<nums.size();i++) 
    {
        tmp.insert({ nums.at(i),i });
        cout << "key: " << nums.at(i) << " value: " << i << endl;
    }

    for (int j = 0; j < nums.size(); j++) 
    {
        int pair_value = target - nums.at(j);
        if (tmp.find(pair_value)!=tmp.end())
        {
            // case 1. input: [3,2,4], 6; output: [1,2]
            // case 2. input: [3,3],6; output: [0,1]
            if ((nums.size() >= 3 && pair_value != nums.at(j)) || (nums.size() < 3 && tmp[pair_value] != j))
            {
                result.push_back(j);
                result.push_back(tmp[pair_value]);
                break;
            }
        }
    }
    return result;
}
