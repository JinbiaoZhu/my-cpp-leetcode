#include "maxSubArray.h"
#include <iostream>

using namespace std;

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

int maxSubArray_dp_version(vector<int>& nums)
{
    int numsLength = nums.size();

    if (numsLength == 0)
    {
        return 0;
    }

    // 1. dp[i] ��ʾ�����±� i Ҳ������ nums[i] ��β����������к�
    // 3. dp[0] = nums[0];
    vector<int> dp(numsLength, 0);
    dp[0] = nums[0];

    // 4. ��С����, ��ǰ���
    for (int i = 1; i < numsLength; i++)
    {
        // 2. dp[i] = max(
        //         dp[i-1] + nums[i],  // ��ʾ�¼������ֵ;
        //         nums[i]             // ��ʾ�ж���, ���¿�ʼ
        //     )
        dp[i] = max(
            dp[i - 1] + nums[i],
            nums[i]
        );
    }

    // 5. �˹���ֵģ��
    for (int i : dp) { cout << i << " "; }
    cout << endl;

    // 6. ���ѡȡ dp ��������ֵ
    int current_max = dp[0];
    for (int i = 1; i < dp.size(); i++)
    {
        if (dp[i] > current_max)
        {
            current_max = dp[i];
        }
    }

    return current_max;
}
