#include "canPartition.h"

bool canPartition(vector<int>& nums)
{
    if (nums.size()<=1)
    {
        return false;
    }
    else
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2 == 1)
        {
            return false;
        }
        else
        {
            int target = sum / 2;
            int bag_weight = 100 * 200 / 2 + 1;

            vector<int> weight = nums;
            vector<int> values = nums;

            // 1. ȷ����̬�滮 dp ����: dp[i] ��ʾ����������Ϊ i ʱ���Ա��õ���������� dp[i]
            // 3. ȷ����̬�滮��ʼ��: dp[i] ����ȫΪ 0 ��ʾû��������뱳��������±���������������� 0
            vector<int> dp(bag_weight, 0);

            // 4. ȷ����̬�滮�ı���: ������������˳��, ������������˳��
            for (int i = 0; i < nums.size(); i++)
            {
                for (int j = target; j >= weight[i]; j--)
                {
                    // 2. ȷ����̬�滮������ʽ: dp[i] = max( dp[i-1] , dp[j-weight[i]]+value[i] );
                    dp[j] = max(dp[j], dp[j- weight[i]] + values[i]);
                }
            }
            
            if (dp[target] == target)
            {
                return true;
            }
            else
            {
                return false;
            }

        }
    }
}
