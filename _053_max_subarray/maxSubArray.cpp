#include "maxSubArray.h"

int maxSubArray(vector<int>& nums) {

    int sum = 0;
    int max_val = nums[0];

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum > max_val){
            max_val = sum;
        }

        if (sum <= 0){
            sum = 0;
        }
    }

    return max_val;
}