#include "four_sum.h"
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    for (int k = 0; k < nums.size(); k++) 
    {
        if (nums[k] >= 0 && nums[k] > target) 
        {
            break;
        }

        if (k > 0 && nums[k] == nums[k - 1]) 
        {
            continue;
        }

        for (int i = k + 1; i < nums.size(); i++) 
        {
            if (nums[i] + nums[k] > target && nums[i] + nums[k] >= 0) 
            {
                break;
            }
            
            if (i > k + 1 && nums[i] == nums[i - 1]) 
            {
                continue;
            }

            // start here
            int left = i + 1;
            int right = nums.size()-1;

            while (right>left)
            {
                if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target)
                {
                    right--; 
                }
                else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target)
                {
                    left++; 
                }
                else 
                {
                    result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                    while (left < right && nums[right - 1] == nums[right])
                    {
                        right--;
                    }
                    while (left < right && nums[left + 1] == nums[left])
                    {
                        left++;
                    }
                    right--;
                    left++;
                }
            }
        }
    }

    return result;
}
